/* A toy re-implementation of CPython's object model.  */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef struct base_obj base_obj;
typedef struct type_obj type_obj;
typedef struct string_obj string_obj;

struct base_obj
{
  struct type_obj *ob_type;
  int ob_refcnt;
};

struct type_obj
{
  base_obj tp_base;
};

struct string_obj
{
  base_obj str_base;
  size_t str_len;
  char str_buf[];
};

type_obj type_type = {
  { &type_type, 1},
};

type_obj str_type = {
  { &str_type, 1},
};

base_obj *alloc_obj (type_obj *ob_type, size_t sz)
{
  base_obj *obj = (base_obj *)malloc (sz);
  if (!obj)
    return NULL;
  obj->ob_type = ob_type;
  obj->ob_refcnt = 1;
  return obj;
}

string_obj *new_string_obj (const char *str)
{
  //__analyzer_dump ();
  size_t len = strlen (str);
#if 1
  string_obj *str_obj
    = (string_obj *)alloc_obj (&str_type, sizeof (string_obj) + len + 1);
#else
  string_obj *str_obj = (string_obj *)malloc (sizeof (string_obj) + len + 1);
  if (!str_obj)
    return NULL;
  str_obj->str_base.ob_type = &str_type;
  str_obj->str_base.ob_refcnt = 1;
#endif
  str_obj->str_len = len; /* { dg-warning "dereference of NULL 'str_obj'" } */
  memcpy (str_obj->str_buf, str, len);
  str_obj->str_buf[len] = '\0';
  return str_obj;
}

void unref (string_obj *obj)
{
  if (--obj->str_base.ob_refcnt == 0)
    free (obj);
}

void test_1 (const char *str)
{
  string_obj *obj = new_string_obj (str);
  if (obj)
    unref (obj);
} /* { dg-bogus "leak of 'obj'" "" { xfail *-*-* } } */
/* TODO(xfail): the false leak report involves the base_obj.ob_refcnt
   being 1, but the string_obj.str_base.ob_refcnt being unknown (when
   they ought to be the same region), thus allowing for a path in which
   the object is allocated but not freed.  */

