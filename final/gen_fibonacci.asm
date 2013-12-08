.data
potato: .word 0
#special data
display: .word 0:9
string_1: .asciiz " = "
string_2: .asciiz "\n"
string_0: .asciiz "fibonacci "


.text
Fibonacci_class_not_a_function:
j main

fibonacci:
#prolog for fibonacci
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
addi $sp, $sp, -4
sw $a0, 0($sp)
#end of prolog for fibonacci
# function body code
 #generating scope registration logic...
 la $t0, display
 lw $t1, 4($t0)
 addi $sp, $sp, -4
 sw $t1, 0($sp)
 addi $sp, $sp, -8   #reservar el espacio para el scope
 sw $sp, 4($t0)
 #end of scope registration
 # scope level 1
    # x
    addi $s0, $fp, -4
    #param: x offset -4
    lw $s0, 0($s0)
    li $t0, 0
   seq $t0, $s0, $t0
    # x
    addi $s0, $fp, -4
    #param: x offset -4
    lw $s0, 0($s0)
    li $t1, 1
   seq $t1, $s0, $t1
  bne $t0, $zero, true_0
  bne $t1, $zero, true_0
  li $t0, 0
  j end_0
  true_0:
  li $t0, 1
  end_0:
  beq $t0, $zero, else_label_0
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
 addi $sp, $sp, 8
 la $t2 , display
 lw  $t3 , 0($sp)
 addi $sp, $sp, 4
 sw $t3, 4($t2)
 #end of scope unregistration


    #termino unregisterAll
    j function_end_0

   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t2, display
   lw $t3, 0($sp)
   addi $sp, $sp, 4
   sw $t3, 8($t2)
   #end of scope unregistration

  else_label_0:
   #generating scope registration logic...
   la $t2, display
   lw $t3, 8($t2)
   addi $sp, $sp, -4
   sw $t3, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t2)
   #end of scope registration
   # scope level 2
      #method call fibonacci
      addi $sp, $sp, -4#arguments
       # x
       addi $s0, $fp, -4
       #param: x offset -4
       lw $s0, 0($s0)
       li $t2, 1
      sub $t2, $s0, $t2
      #saving previous value
      sw $a0, 0($sp)
      #end saving
     move $a0, $t2
     jal fibonacci
      lw $a0, 0($sp)
      addi $sp, $sp, 4
      #end method callfibonacci
     #var f1
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 4
     #local: f1 offset 0 level 1
    sw $v0, 0($s0)
#termino assignment...
      la $t2, string_0
    move $a0, $t2
    li $v0, 4
    syscall
      # x
      addi $s0, $fp, -4
      #param: x offset -4
      lw $s0, 0($s0)
      li $t2, 1
     sub $t2, $s0, $t2
    move $a0, $t2
    li $v0, 1
    syscall
      la $t2, string_1
    move $a0, $t2
    li $v0, 4
    syscall
     # f1
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 4
     #local: f1 offset 0 level 1
     lw $s0, 0($s0)
    move $a0, $s0
    li $v0, 1
    syscall
      la $t2, string_2
    move $a0, $t2
    li $v0, 4
    syscall
      #method call fibonacci
      addi $sp, $sp, -4#arguments
       # x
       addi $s0, $fp, -4
       #param: x offset -4
       lw $s0, 0($s0)
       li $t2, 2
      sub $t2, $s0, $t2
      #saving previous value
      sw $a0, 0($sp)
      #end saving
     move $a0, $t2
     jal fibonacci
      lw $a0, 0($sp)
      addi $sp, $sp, 4
      #end method callfibonacci
     #var f2
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: f2 offset 4 level 1
    sw $v0, 0($s0)
#termino assignment...
      la $t2, string_0
    move $a0, $t2
    li $v0, 4
    syscall
      # x
      addi $s0, $fp, -4
      #param: x offset -4
      lw $s0, 0($s0)
      li $t2, 2
     sub $t2, $s0, $t2
    move $a0, $t2
    li $v0, 1
    syscall
      la $t2, string_1
    move $a0, $t2
    li $v0, 4
    syscall
     # f2
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: f2 offset 4 level 1
     lw $s0, 0($s0)
    move $a0, $s0
    li $v0, 1
    syscall
      la $t2, string_2
    move $a0, $t2
    li $v0, 4
    syscall
      # f1
      la $s0, display
      addi $s0, $s0, 4
      lw $s0, 0($s0)
      addi $s0, $s0, 4
      #local: f1 offset 0 level 1
      lw $s0, 0($s0)
      # f2
      la $s1, display
      addi $s1, $s1, 4
      lw $s1, 0($s1)
      addi $s1, $s1, 0
      #local: f2 offset 4 level 1
      lw $s1, 0($s1)
     add $t2, $s0, $s1
    move $v0, $t2
    #unregisterAll ...
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t3 , display
   lw  $t4 , 0($sp)
   addi $sp, $sp, 4
   sw $t4, 8($t3)
   #end of scope unregistration

 #starting scope unregistration code...
 addi $sp, $sp, 8
 la $t3 , display
 lw  $t4 , 0($sp)
 addi $sp, $sp, 4
 sw $t4, 4($t3)
 #end of scope unregistration


    #termino unregisterAll
    j function_end_0

   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t3, display
   lw $t4, 0($sp)
   addi $sp, $sp, 4
   sw $t4, 8($t3)
   #end of scope unregistration

 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 8
 la $t0, display
 lw $t3, 0($sp)
 addi $sp, $sp, 4
 sw $t3, 4($t0)
 #end of scope unregistration
# end of function body code
function_end_0:
#epilog for fibonacci
lw $a0, 0($sp)
addi $sp, $sp, 4
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
#end of epilog for fibonacci
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
    #method call fibonacci
    addi $sp, $sp, -4#arguments
    li $t0, 5
    #saving previous value
    sw $a0, 0($sp)
    #end saving
   move $a0, $t0
   jal fibonacci
    lw $a0, 0($sp)
    addi $sp, $sp, 4
    #end method callfibonacci
   #var t
   la $s0, display
   addi $s0, $s0, 4
   lw $s0, 0($s0)
   addi $s0, $s0, 0
   #local: t offset 0 level 1
  sw $v0, 0($s0)
#termino assignment...
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
 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 4
 la $t0, display
 lw $t1, 0($sp)
 addi $sp, $sp, 4
 sw $t1, 4($t0)
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


