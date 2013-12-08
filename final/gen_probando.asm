.data
hola1: .word 0
hola2: .word 0
#special data
display: .word 0:9


.text
hola:
j main

funcionHola:
#prolog for funcionHola
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
addi $sp, $sp, -8
sw $a0, 0($sp)
sw $a1, 4($sp)
#end of prolog for funcionHola
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
   # i1
   addi $s0, $fp, -8
   #param: i1 offset -8
   lw $s0, 0($s0)
   # i2
   addi $s1, $fp, -4
   #param: i2 offset -4
   lw $s1, 0($s1)
  seq $t0, $s0, $s1
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
     # i1
     addi $s0, $fp, -8
     #param: i1 offset -8
     lw $s0, 0($s0)
    move $v0, $s0
    #unregisterAll ...
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t1 , display
   lw  $t2 , 0($sp)
   addi $sp, $sp, 4
   sw $t2, 8($t1)
   #end of scope unregistration

 #starting scope unregistration code...
 addi $sp, $sp, 0
 la $t1 , display
 lw  $t2 , 0($sp)
 addi $sp, $sp, 4
 sw $t2, 4($t1)
 #end of scope unregistration


    #termino unregisterAll
    j function_end_0

   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t1, display
   lw $t2, 0($sp)
   addi $sp, $sp, 4
   sw $t2, 8($t1)
   #end of scope unregistration

  else_label_0:
    #method call funcionHola
    addi $sp, $sp, -8#arguments
    # i1
    addi $s1, $fp, -8
    #param: i1 offset -8
    lw $s1, 0($s1)
    #saving previous value
    sw $a0, 0($sp)
    #end saving
   move $a0, $s1
     # i2
     addi $s1, $fp, -4
     #param: i2 offset -4
     lw $s1, 0($s1)
     li $t0, 1
    sub $t0, $s1, $t0
    #saving previous value
    sw $a1, 4($sp)
    #end saving
   move $a1, $t0
   jal funcionHola
    lw $a1, 0($sp)
    lw $a0, 4($sp)
    addi $sp, $sp, 8
    #end method callfuncionHola
  #unregisterAll ...
 #starting scope unregistration code...
 addi $sp, $sp, 0
 la $t0 , display
 lw  $t1 , 0($sp)
 addi $sp, $sp, 4
 sw $t1, 4($t0)
 #end of scope unregistration


  #termino unregisterAll
  j function_end_0

 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 0
 la $t0, display
 lw $t1, 0($sp)
 addi $sp, $sp, 4
 sw $t1, 4($t0)
 #end of scope unregistration
# end of function body code
function_end_0:
#epilog for funcionHola
lw $a0, 0($sp)
lw $a1, 4($sp)
addi $sp, $sp, 8
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
#end of epilog for funcionHola
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
    #method call funcionHola
    addi $sp, $sp, -8#arguments
    li $t0, 3
    #saving previous value
    sw $a0, 0($sp)
    #end saving
   move $a0, $t0
    li $t0, 10
    #saving previous value
    sw $a1, 4($sp)
    #end saving
   move $a1, $t0
   jal funcionHola
    lw $a1, 0($sp)
    lw $a0, 4($sp)
    addi $sp, $sp, 8
    #end method callfuncionHola
   #var x
   la $s0, display
   addi $s0, $s0, 4
   lw $s0, 0($s0)
   addi $s0, $s0, 0
   #local: x offset 0 level 1
  sw $v0, 0($s0)
#termino assignment...
   # x
   la $s0, display
   addi $s0, $s0, 4
   lw $s0, 0($s0)
   addi $s0, $s0, 0
   #local: x offset 0 level 1
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


