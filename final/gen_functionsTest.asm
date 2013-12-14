.data
#special data
display: .word 0:9
string_0: .asciiz "\n"


.text
functionsTest_class_not_a_function:
j main

function:
#prolog for function
addi $t0, $sp,24
addi $sp, $sp, -32 
sw $s0, 0($sp)
sw $s1, 4($sp)
sw $s2, 8($sp)
sw $s3, 12($sp)
sw $s4, 16($sp)
sw $s5, 20($sp)
sw $s6, 24($sp)
sw $s7, 28($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
move $fp, $sp
addi $sp, $sp, -24
sw $a0, 0($sp)
sw $a1, 4($sp)
sw $a2, 8($sp)
sw $a3, 12($sp)
lw $t1, -8($t0)
sw $t1, 16($sp)
lw $t1, -4($t0)
sw $t1, 20($sp)
#end of prolog for function
# function body code
 #generating scope registration logic...
 la $t0, display
 lw $t1, 4($t0)
 addi $sp, $sp, -4
 sw $t1, 0($sp)
 addi $sp, $sp, 0   #reservar el espacio para el scope
 sw $sp, 4($t0)
 #end of scope registration
 # scope level 1
   # a
   addi $s0, $fp, -24
   #param: a offset -24
   lw $s0, 0($s0)
  move $a0, $s0
  li $v0, 1
  syscall
    la $t0, string_0
  move $a0, $t0
  li $v0, 4
  syscall
   # b
   addi $s0, $fp, -20
   #param: b offset -20
   lw $s0, 0($s0)
  move $a0, $s0
  li $v0, 1
  syscall
    la $t0, string_0
  move $a0, $t0
  li $v0, 4
  syscall
   # c
   addi $s0, $fp, -16
   #param: c offset -16
   lw $s0, 0($s0)
  move $a0, $s0
  li $v0, 1
  syscall
    la $t0, string_0
  move $a0, $t0
  li $v0, 4
  syscall
   # d
   addi $s0, $fp, -12
   #param: d offset -12
   lw $s0, 0($s0)
  move $a0, $s0
  li $v0, 1
  syscall
    la $t0, string_0
  move $a0, $t0
  li $v0, 4
  syscall
   # e
   addi $s0, $fp, -8
   #param: e offset -8
   lw $s0, 0($s0)
  move $a0, $s0
  li $v0, 1
  syscall
    la $t0, string_0
  move $a0, $t0
  li $v0, 4
  syscall
   # f
   addi $s0, $fp, -4
   #param: f offset -4
   lw $s0, 0($s0)
  move $a0, $s0
  li $v0, 1
  syscall
    la $t0, string_0
  move $a0, $t0
  li $v0, 4
  syscall
   li $t0, 1
  move $v0, $t0
  #unregisterAll ...
 #starting scope unregistration code...
 addi $sp, $sp, 0
 la $t1 , display
 lw  $t2 , 0($sp)
 addi $sp, $sp, 4
 sw $t2, 4($t1)
 #end of scope unregistration


  #termino unregisterAll
  j function_end_0

 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 0
 la $t1, display
 lw $t2, 0($sp)
 addi $sp, $sp, 4
 sw $t2, 4($t1)
 #end of scope unregistration
# end of function body code
function_end_0:
#epilog for function
lw $a0, 0($sp)
lw $a1, 4($sp)
lw $a2, 8($sp)
lw $a3, 12($sp)
addi $sp, $sp, 24
lw $fp, 4($sp)
lw $ra, 0($sp)
addi $sp, $sp, 8
lw $s0, 0($sp)
lw $s1, 4($sp)
lw $s2, 8($sp)
lw $s3, 12($sp)
lw $s4, 16($sp)
lw $s5, 20($sp)
lw $s6, 24($sp)
lw $s7, 28($sp)
addi $sp, $sp, 32
#end of epilog for function
jr $ra


main:
#prolog for main
addi $sp, $sp, -32 
sw $s0, 0($sp)
sw $s1, 4($sp)
sw $s2, 8($sp)
sw $s3, 12($sp)
sw $s4, 16($sp)
sw $s5, 20($sp)
sw $s6, 24($sp)
sw $s7, 28($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
move $fp, $sp
addi $sp, $sp, -0
#end of prolog for main
# function body code
 #generating scope registration logic...
 la $t0, display
 lw $t1, 4($t0)
 addi $sp, $sp, -4
 sw $t1, 0($sp)
 addi $sp, $sp, 0   #reservar el espacio para el scope
 sw $sp, 4($t0)
 #end of scope registration
 # scope level 1
    #method call function
    addi $sp, $sp, -24#arguments
    li $t0, 1
    #saving previous value
    sw $a0, 0($sp)
    #end saving
   move $a0, $t0
    li $t0, 2
    #saving previous value
    sw $a1, 4($sp)
    #end saving
   move $a1, $t0
    li $t0, 3
    #saving previous value
    sw $a2, 8($sp)
    #end saving
   move $a2, $t0
    li $t0, 4
    #saving previous value
    sw $a3, 12($sp)
    #end saving
   move $a3, $t0
    li $t0, 5
    sw $t0, 16($sp)
    li $t1, 7
    sw $t1, 20($sp)
   jal function
    lw $a3, 0($sp)
    lw $a2, 4($sp)
    lw $a1, 8($sp)
    lw $a0, 12($sp)
    addi $sp, $sp, 24
    #end method callfunction
  move $a0, $v0
  li $v0, 1
  syscall
 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 0
 la $t2, display
 lw $t3, 0($sp)
 addi $sp, $sp, 4
 sw $t3, 4($t2)
 #end of scope unregistration
# end of function body code
li $v0, 10
syscall
function_end_1:
#epilog for main
addi $sp, $sp, 0
lw $fp, 4($sp)
lw $ra, 0($sp)
addi $sp, $sp, 8
lw $s0, 0($sp)
lw $s1, 4($sp)
lw $s2, 8($sp)
lw $s3, 12($sp)
lw $s4, 16($sp)
lw $s5, 20($sp)
lw $s6, 24($sp)
lw $s7, 28($sp)
addi $sp, $sp, 32
#end of epilog for main
jr $ra


