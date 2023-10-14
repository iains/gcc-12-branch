/* { dg-do "compile" } */
/* { dg-options "-O1" } */
/* { dg-skip-if "unimplemented patchable function entry" *-*-darwin* } */

/* Test the placement of the .LPFE1 label.  */

void
__attribute__ ((target("branch-protection=bti"),
		patchable_function_entry (1, 0)))
f10_bti ()
{
}
/* { dg-final { scan-assembler "hint\t34 // bti c\n.*\.LPFE1:\n\tnop\n.*\tret\n" } } */
