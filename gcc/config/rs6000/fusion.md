;; -*- buffer-read-only: t -*-
;; Generated automatically by genfusion.pl

;; Copyright (C) 2020 Free Software Foundation, Inc.
;;
;; This file is part of GCC.
;;
;; GCC is free software; you can redistribute it and/or modify it under
;; the terms of the GNU General Public License as published by the Free
;; Software Foundation; either version 3, or (at your option) any later
;; version.
;;
;; GCC is distributed in the hope that it will be useful, but WITHOUT ANY
;; WARRANTY; without even the implied warranty of MERCHANTABILITY or
;; FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
;; for more details.
;;
;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is DI result mode is clobber compare mode is CC extend is none
(define_insn_and_split "*ld_cmpdi_cr0_DI_clobber_CC_none"
  [(set (match_operand:CC 2 "cc_reg_operand" "=x")
        (compare:CC (match_operand:DI 1 "non_update_memory_operand" "m")
                 (match_operand:DI 3 "const_m1_to_1_operand" "n")))
   (clobber (match_scratch:DI 0 "=r"))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "ld%X1 %0,%1\;cmpdi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), DImode, NON_PREFIXED_DS))"
  [(set (match_dup 0) (match_dup 1))
   (set (match_dup 2)
        (compare:CC (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is DI result mode is clobber compare mode is CCUNS extend is none
(define_insn_and_split "*ld_cmpldi_cr0_DI_clobber_CCUNS_none"
  [(set (match_operand:CCUNS 2 "cc_reg_operand" "=x")
        (compare:CCUNS (match_operand:DI 1 "non_update_memory_operand" "m")
                 (match_operand:DI 3 "const_0_to_1_operand" "n")))
   (clobber (match_scratch:DI 0 "=r"))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "ld%X1 %0,%1\;cmpldi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), DImode, NON_PREFIXED_DS))"
  [(set (match_dup 0) (match_dup 1))
   (set (match_dup 2)
        (compare:CCUNS (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is DI result mode is DI compare mode is CC extend is none
(define_insn_and_split "*ld_cmpdi_cr0_DI_DI_CC_none"
  [(set (match_operand:CC 2 "cc_reg_operand" "=x")
        (compare:CC (match_operand:DI 1 "non_update_memory_operand" "m")
                 (match_operand:DI 3 "const_m1_to_1_operand" "n")))
   (set (match_operand:DI 0 "gpc_reg_operand" "=r") (match_dup 1))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "ld%X1 %0,%1\;cmpdi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), DImode, NON_PREFIXED_DS))"
  [(set (match_dup 0) (match_dup 1))
   (set (match_dup 2)
        (compare:CC (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is DI result mode is DI compare mode is CCUNS extend is none
(define_insn_and_split "*ld_cmpldi_cr0_DI_DI_CCUNS_none"
  [(set (match_operand:CCUNS 2 "cc_reg_operand" "=x")
        (compare:CCUNS (match_operand:DI 1 "non_update_memory_operand" "m")
                 (match_operand:DI 3 "const_0_to_1_operand" "n")))
   (set (match_operand:DI 0 "gpc_reg_operand" "=r") (match_dup 1))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "ld%X1 %0,%1\;cmpldi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), DImode, NON_PREFIXED_DS))"
  [(set (match_dup 0) (match_dup 1))
   (set (match_dup 2)
        (compare:CCUNS (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is SI result mode is clobber compare mode is CC extend is none
(define_insn_and_split "*lwa_cmpdi_cr0_SI_clobber_CC_none"
  [(set (match_operand:CC 2 "cc_reg_operand" "=x")
        (compare:CC (match_operand:SI 1 "non_update_memory_operand" "m")
                 (match_operand:SI 3 "const_m1_to_1_operand" "n")))
   (clobber (match_scratch:SI 0 "=r"))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lwa%X1 %0,%1\;cmpdi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), SImode, NON_PREFIXED_DS))"
  [(set (match_dup 0) (match_dup 1))
   (set (match_dup 2)
        (compare:CC (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is SI result mode is clobber compare mode is CCUNS extend is none
(define_insn_and_split "*lwz_cmpldi_cr0_SI_clobber_CCUNS_none"
  [(set (match_operand:CCUNS 2 "cc_reg_operand" "=x")
        (compare:CCUNS (match_operand:SI 1 "non_update_memory_operand" "m")
                 (match_operand:SI 3 "const_0_to_1_operand" "n")))
   (clobber (match_scratch:SI 0 "=r"))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lwz%X1 %0,%1\;cmpldi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), SImode, NON_PREFIXED_D))"
  [(set (match_dup 0) (match_dup 1))
   (set (match_dup 2)
        (compare:CCUNS (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is SI result mode is SI compare mode is CC extend is none
(define_insn_and_split "*lwa_cmpdi_cr0_SI_SI_CC_none"
  [(set (match_operand:CC 2 "cc_reg_operand" "=x")
        (compare:CC (match_operand:SI 1 "non_update_memory_operand" "m")
                 (match_operand:SI 3 "const_m1_to_1_operand" "n")))
   (set (match_operand:SI 0 "gpc_reg_operand" "=r") (match_dup 1))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lwa%X1 %0,%1\;cmpdi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), SImode, NON_PREFIXED_DS))"
  [(set (match_dup 0) (match_dup 1))
   (set (match_dup 2)
        (compare:CC (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is SI result mode is SI compare mode is CCUNS extend is none
(define_insn_and_split "*lwz_cmpldi_cr0_SI_SI_CCUNS_none"
  [(set (match_operand:CCUNS 2 "cc_reg_operand" "=x")
        (compare:CCUNS (match_operand:SI 1 "non_update_memory_operand" "m")
                 (match_operand:SI 3 "const_0_to_1_operand" "n")))
   (set (match_operand:SI 0 "gpc_reg_operand" "=r") (match_dup 1))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lwz%X1 %0,%1\;cmpldi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), SImode, NON_PREFIXED_D))"
  [(set (match_dup 0) (match_dup 1))
   (set (match_dup 2)
        (compare:CCUNS (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is SI result mode is EXTSI compare mode is CC extend is sign
(define_insn_and_split "*lwa_cmpdi_cr0_SI_EXTSI_CC_sign"
  [(set (match_operand:CC 2 "cc_reg_operand" "=x")
        (compare:CC (match_operand:SI 1 "non_update_memory_operand" "m")
                 (match_operand:SI 3 "const_m1_to_1_operand" "n")))
   (set (match_operand:EXTSI 0 "gpc_reg_operand" "=r") (sign_extend:EXTSI (match_dup 1)))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lwa%X1 %0,%1\;cmpdi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), SImode, NON_PREFIXED_DS))"
  [(set (match_dup 0) (sign_extend:EXTSI (match_dup 1)))
   (set (match_dup 2)
        (compare:CC (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is SI result mode is EXTSI compare mode is CCUNS extend is zero
(define_insn_and_split "*lwz_cmpldi_cr0_SI_EXTSI_CCUNS_zero"
  [(set (match_operand:CCUNS 2 "cc_reg_operand" "=x")
        (compare:CCUNS (match_operand:SI 1 "non_update_memory_operand" "m")
                 (match_operand:SI 3 "const_0_to_1_operand" "n")))
   (set (match_operand:EXTSI 0 "gpc_reg_operand" "=r") (zero_extend:EXTSI (match_dup 1)))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lwz%X1 %0,%1\;cmpldi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), SImode, NON_PREFIXED_D))"
  [(set (match_dup 0) (zero_extend:EXTSI (match_dup 1)))
   (set (match_dup 2)
        (compare:CCUNS (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is HI result mode is clobber compare mode is CC extend is sign
(define_insn_and_split "*lha_cmpdi_cr0_HI_clobber_CC_sign"
  [(set (match_operand:CC 2 "cc_reg_operand" "=x")
        (compare:CC (match_operand:HI 1 "non_update_memory_operand" "m")
                 (match_operand:HI 3 "const_m1_to_1_operand" "n")))
   (clobber (match_scratch:GPR 0 "=r"))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lha%X1 %0,%1\;cmpdi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), HImode, NON_PREFIXED_D))"
  [(set (match_dup 0) (sign_extend:GPR (match_dup 1)))
   (set (match_dup 2)
        (compare:CC (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is HI result mode is clobber compare mode is CCUNS extend is zero
(define_insn_and_split "*lhz_cmpldi_cr0_HI_clobber_CCUNS_zero"
  [(set (match_operand:CCUNS 2 "cc_reg_operand" "=x")
        (compare:CCUNS (match_operand:HI 1 "non_update_memory_operand" "m")
                 (match_operand:HI 3 "const_0_to_1_operand" "n")))
   (clobber (match_scratch:GPR 0 "=r"))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lhz%X1 %0,%1\;cmpldi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), HImode, NON_PREFIXED_D))"
  [(set (match_dup 0) (zero_extend:GPR (match_dup 1)))
   (set (match_dup 2)
        (compare:CCUNS (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is HI result mode is EXTHI compare mode is CC extend is sign
(define_insn_and_split "*lha_cmpdi_cr0_HI_EXTHI_CC_sign"
  [(set (match_operand:CC 2 "cc_reg_operand" "=x")
        (compare:CC (match_operand:HI 1 "non_update_memory_operand" "m")
                 (match_operand:HI 3 "const_m1_to_1_operand" "n")))
   (set (match_operand:EXTHI 0 "gpc_reg_operand" "=r") (sign_extend:EXTHI (match_dup 1)))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lha%X1 %0,%1\;cmpdi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), HImode, NON_PREFIXED_D))"
  [(set (match_dup 0) (sign_extend:EXTHI (match_dup 1)))
   (set (match_dup 2)
        (compare:CC (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is HI result mode is EXTHI compare mode is CCUNS extend is zero
(define_insn_and_split "*lhz_cmpldi_cr0_HI_EXTHI_CCUNS_zero"
  [(set (match_operand:CCUNS 2 "cc_reg_operand" "=x")
        (compare:CCUNS (match_operand:HI 1 "non_update_memory_operand" "m")
                 (match_operand:HI 3 "const_0_to_1_operand" "n")))
   (set (match_operand:EXTHI 0 "gpc_reg_operand" "=r") (zero_extend:EXTHI (match_dup 1)))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lhz%X1 %0,%1\;cmpldi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), HImode, NON_PREFIXED_D))"
  [(set (match_dup 0) (zero_extend:EXTHI (match_dup 1)))
   (set (match_dup 2)
        (compare:CCUNS (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is QI result mode is clobber compare mode is CCUNS extend is zero
(define_insn_and_split "*lbz_cmpldi_cr0_QI_clobber_CCUNS_zero"
  [(set (match_operand:CCUNS 2 "cc_reg_operand" "=x")
        (compare:CCUNS (match_operand:QI 1 "non_update_memory_operand" "m")
                 (match_operand:QI 3 "const_0_to_1_operand" "n")))
   (clobber (match_scratch:GPR 0 "=r"))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lbz%X1 %0,%1\;cmpldi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), QImode, NON_PREFIXED_D))"
  [(set (match_dup 0) (zero_extend:GPR (match_dup 1)))
   (set (match_dup 2)
        (compare:CCUNS (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])

;; load-cmpi fusion pattern generated by gen_ld_cmpi_p10
;; load mode is QI result mode is GPR compare mode is CCUNS extend is zero
(define_insn_and_split "*lbz_cmpldi_cr0_QI_GPR_CCUNS_zero"
  [(set (match_operand:CCUNS 2 "cc_reg_operand" "=x")
        (compare:CCUNS (match_operand:QI 1 "non_update_memory_operand" "m")
                 (match_operand:QI 3 "const_0_to_1_operand" "n")))
   (set (match_operand:GPR 0 "gpc_reg_operand" "=r") (zero_extend:GPR (match_dup 1)))]
  "(TARGET_P10_FUSION && TARGET_P10_FUSION_LD_CMPI)"
  "lbz%X1 %0,%1\;cmpldi 0,%0,%3"
  "&& reload_completed
   && (cc_reg_not_cr0_operand (operands[2], CCmode)
       || !address_is_non_pfx_d_or_x (XEXP (operands[1],0), QImode, NON_PREFIXED_D))"
  [(set (match_dup 0) (zero_extend:GPR (match_dup 1)))
   (set (match_dup 2)
        (compare:CCUNS (match_dup 0)
		    (match_dup 3)))]
  ""
  [(set_attr "type" "load")
   (set_attr "cost" "8")
   (set_attr "length" "8")])
