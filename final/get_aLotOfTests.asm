.data
array: .space 40 # 10 integers
b_variable1: .word 0
b_variable2: .word 0
i_variable1: .word 0
i_variable2: .word 10
#special data
display: .word 0:9
string_8: .asciiz "OK"
string_7: .asciiz "WTF!"
string_1: .asciiz "\n"
string_6: .asciiz "]="
string_5: .asciiz "array["
string_3: .asciiz "b_variable1: "
string_4: .asciiz "b_variable2: "
string_0: .asciiz "i_variable1: "
string_2: .asciiz "i_variable2: "
string_9: .asciiz "t: "


.text
alltest_class_not_a_function:
j main

boolFunction1:
#prolog for boolFunction1
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
#end of prolog for boolFunction1
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
   li $t0, 0
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
#epilog for boolFunction1
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
#end of epilog for boolFunction1
jr $ra


boolFunction2:
#prolog for boolFunction2
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
#end of prolog for boolFunction2
# function body code
 #generating scope registration logic...
 la $t0, display
 lw $t1, 4($t0)
 addi $sp, $sp, -4
 sw $t1, 0($sp)
 addi $sp, $sp, -4   #reservar el espacio para el scope
 sw $sp, 4($t0)
 #end of scope registration
 # scope level 1
   #generating scope registration logic...
   la $t0, display
   lw $t1, 8($t0)
   addi $sp, $sp, -4
   sw $t1, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t0)
   #end of scope registration
   # scope level 2
     li $t0, 0
     #var i
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: i offset 0 level 1
    sw $t0, 0($s0)
#termino assignment...
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t0, display
   lw $t1, 0($sp)
   addi $sp, $sp, 4
   sw $t1, 8($t0)
   #end of scope unregistration
  for_label_0:
   li $t0, 1
   beq $t0, $zero, out_of_for_0
   #generating scope registration logic...
   la $t1, display
   lw $t2, 8($t1)
   addi $sp, $sp, -4
   sw $t2, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t1)
   #end of scope registration
   # scope level 2
     li $t1, 1
    move $v0, $t1
    #unregisterAll ...
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t2 , display
   lw  $t3 , 0($sp)
   addi $sp, $sp, 4
   sw $t3, 8($t2)
   #end of scope unregistration

 #starting scope unregistration code...
 addi $sp, $sp, 4
 la $t2 , display
 lw  $t3 , 0($sp)
 addi $sp, $sp, 4
 sw $t3, 4($t2)
 #end of scope unregistration


    #termino unregisterAll
    j function_end_1
#epilog for boolFunction1
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
#end of epilog for boolFunction1

   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t2, display
   lw $t3, 0($sp)
   addi $sp, $sp, 4
   sw $t3, 8($t2)
   #end of scope unregistration
   continue_point_0: 
   #generating scope registration logic...
   la $t2, display
   lw $t3, 8($t2)
   addi $sp, $sp, -4
   sw $t3, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t2)
   #end of scope registration
   # scope level 2
      # i
      la $s0, display
      addi $s0, $s0, 4
      lw $s0, 0($s0)
      addi $s0, $s0, 0
      #local: i offset 0 level 1
      lw $s0, 0($s0)
      li $t2, 1
     add $t2, $s0, $t2
     #var i
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: i offset 0 level 1
    sw $t2, 0($s0)
#termino assignment...
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t2, display
   lw $t3, 0($sp)
   addi $sp, $sp, 4
   sw $t3, 8($t2)
   #end of scope unregistration
  j for_label_0
  out_of_for_0:
 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 4
 la $t2, display
 lw $t3, 0($sp)
 addi $sp, $sp, 4
 sw $t3, 4($t2)
 #end of scope unregistration
# end of function body code
function_end_1:
#epilog for boolFunction2
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
#end of epilog for boolFunction2
jr $ra


fillArray:
#prolog for fillArray
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
#end of prolog for fillArray
# function body code
 #generating scope registration logic...
 la $t0, display
 lw $t1, 4($t0)
 addi $sp, $sp, -4
 sw $t1, 0($sp)
 addi $sp, $sp, -4   #reservar el espacio para el scope
 sw $sp, 4($t0)
 #end of scope registration
 # scope level 1
   #generating scope registration logic...
   la $t0, display
   lw $t1, 8($t0)
   addi $sp, $sp, -4
   sw $t1, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t0)
   #end of scope registration
   # scope level 2
     li $t0, 0
     #var i
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: i offset 0 level 1
    sw $t0, 0($s0)
#termino assignment...
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t0, display
   lw $t1, 0($sp)
   addi $sp, $sp, 4
   sw $t1, 8($t0)
   #end of scope unregistration
  for_label_1:
    # i
    la $s0, display
    addi $s0, $s0, 4
    lw $s0, 0($s0)
    addi $s0, $s0, 0
    #local: i offset 0 level 1
    lw $s0, 0($s0)
    li $t0, 10
   slt $t0, $s0, $t0
   beq $t0, $zero, out_of_for_1
   #generating scope registration logic...
   la $t1, display
   lw $t2, 8($t1)
   addi $sp, $sp, -4
   sw $t2, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t1)
   #end of scope registration
   # scope level 2
    li $v0, 5
    syscall
     #var array
     la $s0, array
      # i
      la $s1, display
      addi $s1, $s1, 4
      lw $s1, 0($s1)
      addi $s1, $s1, 0
      #local: i offset 0 level 1
      lw $s1, 0($s1)
      sll $s1, $s1, 2# multiply by 4
     add $s0, $s0, $s1
    sw $v0, 0($s0)
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t1, display
   lw $t2, 0($sp)
   addi $sp, $sp, 4
   sw $t2, 8($t1)
   #end of scope unregistration
   continue_point_1: 
   #generating scope registration logic...
   la $t1, display
   lw $t2, 8($t1)
   addi $sp, $sp, -4
   sw $t2, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t1)
   #end of scope registration
   # scope level 2
      # i
      la $s2, display
      addi $s2, $s2, 4
      lw $s2, 0($s2)
      addi $s2, $s2, 0
      #local: i offset 0 level 1
      lw $s2, 0($s2)
      li $t1, 1
     add $t1, $s2, $t1
     #var i
     la $s2, display
     addi $s2, $s2, 4
     lw $s2, 0($s2)
     addi $s2, $s2, 0
     #local: i offset 0 level 1
    sw $t1, 0($s2)
#termino assignment...
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t1, display
   lw $t2, 0($sp)
   addi $sp, $sp, 4
   sw $t2, 8($t1)
   #end of scope unregistration
  j for_label_1
  out_of_for_1:
 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 4
 la $t1, display
 lw $t2, 0($sp)
 addi $sp, $sp, 4
 sw $t2, 4($t1)
 #end of scope unregistration
# end of function body code
function_end_2:
#epilog for fillArray
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
#end of epilog for fillArray
jr $ra


intFunction1:
#prolog for intFunction1
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
#end of prolog for intFunction1
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
    li $t0, 1
       li $t1, 2
       li $t2, 3
      mul $t1, $t1, $t2
      li $t2, 4
     div $t1, $t1, $t2
     li $t2, 5
    rem $t1, $t1, $t2
   add $t0, $t0, $t1
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
  j function_end_3
#epilog for fillArray
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
#end of epilog for fillArray

 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 0
 la $t1, display
 lw $t2, 0($sp)
 addi $sp, $sp, 4
 sw $t2, 4($t1)
 #end of scope unregistration
# end of function body code
function_end_3:
#epilog for intFunction1
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
#end of epilog for intFunction1
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
 addi $sp, $sp, -4   #reservar el espacio para el scope
 sw $sp, 4($t0)
 #end of scope registration
 # scope level 1
 #saving parameters because of method call
 addi $sp, $sp, -16
 sw $a0, 0($sp)
 sw $a1, 4($sp)
 sw $a2, 8($sp)
 sw $a3, 12($sp)
 #end saving parameters because of method call
   #method call printDefaultValues
   addi $sp, $sp, 0#arguments
  jal printDefaultValues
   addi $sp, $sp, 0
   #end method callprintDefaultValues
 #restoring parameters because of method call
 lw $a0, 0($sp)
 lw $a1, 4($sp)
 lw $a2, 8($sp)
 lw $a3, 12($sp)
 addi $sp, $sp, 16
 #end restoring parameters because of method call
 #saving parameters because of method call
 addi $sp, $sp, -16
 sw $a0, 0($sp)
 sw $a1, 4($sp)
 sw $a2, 8($sp)
 sw $a3, 12($sp)
 #end saving parameters because of method call
   #method call fillArray
   addi $sp, $sp, 0#arguments
  jal fillArray
   addi $sp, $sp, 0
   #end method callfillArray
 #restoring parameters because of method call
 lw $a0, 0($sp)
 lw $a1, 4($sp)
 lw $a2, 8($sp)
 lw $a3, 12($sp)
 addi $sp, $sp, 16
 #end restoring parameters because of method call
 #saving parameters because of method call
 addi $sp, $sp, -16
 sw $a0, 0($sp)
 sw $a1, 4($sp)
 sw $a2, 8($sp)
 sw $a3, 12($sp)
 #end saving parameters because of method call
   #method call printDefaultValues
   addi $sp, $sp, 0#arguments
  jal printDefaultValues
   addi $sp, $sp, 0
   #end method callprintDefaultValues
 #restoring parameters because of method call
 lw $a0, 0($sp)
 lw $a1, 4($sp)
 lw $a2, 8($sp)
 lw $a3, 12($sp)
 addi $sp, $sp, 16
 #end restoring parameters because of method call
   #method call boolFunction1
   addi $sp, $sp, 0#arguments
  jal boolFunction1
   addi $sp, $sp, 0
   #end method callboolFunction1
  beq $v0, $zero, else_label_0
   #generating scope registration logic...
   la $t0, display
   lw $t1, 8($t0)
   addi $sp, $sp, -4
   sw $t1, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t0)
   #end of scope registration
   # scope level 2
      la $t0, string_7
    move $a0, $t0
    li $v0, 4
    syscall
      la $t0, string_1
    move $a0, $t0
    li $v0, 4
    syscall
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t0, display
   lw $t1, 0($sp)
   addi $sp, $sp, 4
   sw $t1, 8($t0)
   #end of scope unregistration

  else_label_0:
   #generating scope registration logic...
   la $t0, display
   lw $t1, 8($t0)
   addi $sp, $sp, -4
   sw $t1, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t0)
   #end of scope registration
   # scope level 2
      la $t0, string_8
    move $a0, $t0
    li $v0, 4
    syscall
      la $t0, string_1
    move $a0, $t0
    li $v0, 4
    syscall
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t0, display
   lw $t1, 0($sp)
   addi $sp, $sp, 4
   sw $t1, 8($t0)
   #end of scope unregistration

    #method call intFunction1
    addi $sp, $sp, 0#arguments
   jal intFunction1
    addi $sp, $sp, 0
    #end method callintFunction1
  move $a0, $v0
  li $v0, 1
  syscall
    li $t0, 2
    li $t1, 3
   seq $t0, $t0, $t1
  move $a0, $t0
  li $v0, 1
  syscall
   li $t0, 10
   #var t
   la $s0, display
   addi $s0, $s0, 4
   lw $s0, 0($s0)
   addi $s0, $s0, 0
   #local: t offset 0 level 1
  sw $t0, 0($s0)
#termino assignment...
  while_label_0:
    # t
    la $s0, display
    addi $s0, $s0, 4
    lw $s0, 0($s0)
    addi $s0, $s0, 0
    #local: t offset 0 level 1
    lw $s0, 0($s0)
    li $t0, 100
   slt $t0, $s0, $t0
   beq $t0, $zero, out_of_while_0
   #generating scope registration logic...
   la $t1, display
   lw $t2, 8($t1)
   addi $sp, $sp, -4
   sw $t2, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t1)
   #end of scope registration
   # scope level 2
      la $t1, string_9
    move $a0, $t1
    li $v0, 4
    syscall
     # t
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: t offset 0 level 1
     lw $s0, 0($s0)
    move $a0, $s0
    li $v0, 1
    syscall
      la $t1, string_1
    move $a0, $t1
    li $v0, 4
    syscall
      # t
      la $s0, display
      addi $s0, $s0, 4
      lw $s0, 0($s0)
      addi $s0, $s0, 0
      #local: t offset 0 level 1
      lw $s0, 0($s0)
      li $t1, 10
     add $t1, $s0, $t1
     #var t
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: t offset 0 level 1
    sw $t1, 0($s0)
#termino assignment...
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t1, display
   lw $t2, 0($sp)
   addi $sp, $sp, 4
   sw $t2, 8($t1)
   #end of scope unregistration
  j while_label_0
  out_of_while_0:
 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 4
 la $t1, display
 lw $t2, 0($sp)
 addi $sp, $sp, 4
 sw $t2, 4($t1)
 #end of scope unregistration
# end of function body code
li $v0, 10
syscall
function_end_4:
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


printDefaultValues:
#prolog for printDefaultValues
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
#end of prolog for printDefaultValues
# function body code
 #generating scope registration logic...
 la $t0, display
 lw $t1, 4($t0)
 addi $sp, $sp, -4
 sw $t1, 0($sp)
 addi $sp, $sp, -4   #reservar el espacio para el scope
 sw $sp, 4($t0)
 #end of scope registration
 # scope level 1
    la $t0, string_0
  move $a0, $t0
  li $v0, 4
  syscall
   # i_variable1
   la $s0, i_variable1
   lw $s0, 0($s0)
  move $a0, $s0
  li $v0, 1
  syscall
    la $t0, string_1
  move $a0, $t0
  li $v0, 4
  syscall
    la $t0, string_2
  move $a0, $t0
  li $v0, 4
  syscall
   # i_variable2
   la $s0, i_variable2
   lw $s0, 0($s0)
  move $a0, $s0
  li $v0, 1
  syscall
    la $t0, string_1
  move $a0, $t0
  li $v0, 4
  syscall
    la $t0, string_3
  move $a0, $t0
  li $v0, 4
  syscall
   # b_variable1
   la $s0, b_variable1
   lw $s0, 0($s0)
  move $a0, $s0
  li $v0, 1
  syscall
    la $t0, string_1
  move $a0, $t0
  li $v0, 4
  syscall
    la $t0, string_4
  move $a0, $t0
  li $v0, 4
  syscall
   # b_variable2
   la $s0, b_variable2
   lw $s0, 0($s0)
  move $a0, $s0
  li $v0, 1
  syscall
    la $t0, string_1
  move $a0, $t0
  li $v0, 4
  syscall
   #generating scope registration logic...
   la $t0, display
   lw $t1, 8($t0)
   addi $sp, $sp, -4
   sw $t1, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t0)
   #end of scope registration
   # scope level 2
     li $t0, 0
     #var i
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: i offset 0 level 1
    sw $t0, 0($s0)
#termino assignment...
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t0, display
   lw $t1, 0($sp)
   addi $sp, $sp, 4
   sw $t1, 8($t0)
   #end of scope unregistration
  for_label_2:
    # i
    la $s0, display
    addi $s0, $s0, 4
    lw $s0, 0($s0)
    addi $s0, $s0, 0
    #local: i offset 0 level 1
    lw $s0, 0($s0)
    li $t0, 10
   slt $t0, $s0, $t0
   beq $t0, $zero, out_of_for_2
   #generating scope registration logic...
   la $t1, display
   lw $t2, 8($t1)
   addi $sp, $sp, -4
   sw $t2, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t1)
   #end of scope registration
   # scope level 2
      la $t1, string_5
    move $a0, $t1
    li $v0, 4
    syscall
     # i
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: i offset 0 level 1
     lw $s0, 0($s0)
    move $a0, $s0
    li $v0, 1
    syscall
      la $t1, string_6
    move $a0, $t1
    li $v0, 4
    syscall
     # array
     la $s0, array
      # i
      la $s1, display
      addi $s1, $s1, 4
      lw $s1, 0($s1)
      addi $s1, $s1, 0
      #local: i offset 0 level 1
      lw $s1, 0($s1)
      sll $s1, $s1, 2# multiply by 4
     add $s0, $s0, $s1
     lw $s0, 0($s0)
    move $a0, $s0
    li $v0, 1
    syscall
      la $t1, string_1
    move $a0, $t1
    li $v0, 4
    syscall
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t1, display
   lw $t2, 0($sp)
   addi $sp, $sp, 4
   sw $t2, 8($t1)
   #end of scope unregistration
   continue_point_2: 
   #generating scope registration logic...
   la $t1, display
   lw $t2, 8($t1)
   addi $sp, $sp, -4
   sw $t2, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t1)
   #end of scope registration
   # scope level 2
      # i
      la $s0, display
      addi $s0, $s0, 4
      lw $s0, 0($s0)
      addi $s0, $s0, 0
      #local: i offset 0 level 1
      lw $s0, 0($s0)
      li $t1, 1
     add $t1, $s0, $t1
     #var i
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: i offset 0 level 1
    sw $t1, 0($s0)
#termino assignment...
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t1, display
   lw $t2, 0($sp)
   addi $sp, $sp, 4
   sw $t2, 8($t1)
   #end of scope unregistration
  j for_label_2
  out_of_for_2:
 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 4
 la $t1, display
 lw $t2, 0($sp)
 addi $sp, $sp, 4
 sw $t2, 4($t1)
 #end of scope unregistration
# end of function body code
function_end_5:
#epilog for printDefaultValues
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
#end of epilog for printDefaultValues
jr $ra


