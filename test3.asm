;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  file name   : factorial_sub.asm                          ;
;  author      : 
;  description : LC4 Assembly program to compute the    ;
;                factorial of a number                  ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
;;; pseudo-code of factorial algorithm
; 
; MAIN
;   A = 6;
;   B = sub_factorial(A);
; SUB_FACTORIAL(int A) {
;   B = A;
;   if (A < 0 || A > 7) {
;     B = -1;
;     return B;
;   }
;   
;   while (A > 1) {
; 	  A = A - 1 ;
; 	  B = B * A ;
;   }
;   return B;
; }
;

;;; TO-DO: Implement the factorial algorithm above using LC4 Assembly instructions

MAIN
  CONST R0, #6    ; A = 6
  CONST R1, #0    ; Initialize B to 0 to avoid garbage value
     
JSR SUB_FACTORIAL

JMP END

.FALIGN
SUB_FACTORIAL
  ADD R1, R0, #0    ; B = A + 0
  CMPI R0, #0   ; sets NZP (A-0)
  BRn TEST_INVALID_A    ; tests NZP (was A - 0 neg?, if yes, go to TEST_INVALID_A)
  CMPI R0, #7   ; sets NZP (A-7) since 7 is the largest possible value without causing overflows if we want our ouput to be using 2C
  BRp TEST_INVALID_A  ; tests NZP (was A - 7 positive?, if yes, go to TEST_INVALID_A)

LOOP 
  CMPI R0, #1     ; sets  NZP (A-1)
  BRnz END_LOOP        ; tests NZP (was A-1 neg or zero?, if yes, goto END)
  ADD R0, R0, #-1  ; A = A - 1
  MUL R1, R1, R0 ; B = B * A
  BRnzp LOOP      ; always goto LOOP
END_LOOP
JMP END_FUNC    ; After the loop, jump to end of function 

TEST_INVALID_A    ; The next line only executed when A is invalid
  CONST R1, #-1    ; B = -1 if A < 0 || A > 7

END_FUNC 
RET

END