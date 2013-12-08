.data
aaaaa: .word 10
array: .space 40 # 10 integers
bbbbb1: .word 20
t: .word 1
x: .word 0
y: .word 0
z: .word 0
#special data
display: .word 0:9
string_0: .asciiz "hola mundo \n"


.text
GreatestCommonDivisor_class_not_a_function:
j main

gcd:
#prolog for gcd
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
#end of prolog for gcd
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
   # b
   addi $s0, $fp, -4
   #param: b offset -4
   lw $s0, 0($s0)
   li $t0, 0
  seq $t0, $s0, $t0
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
     # a
     addi $s0, $fp, -8
     #param: a offset -8
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
   #generating scope registration logic...
   la $t1, display
   lw $t2, 8($t1)
   addi $sp, $sp, -4
   sw $t2, 0($sp)
   addi $sp, $sp, 0   #reservar el espacio para el scope
   sw $sp, 8($t1)
   #end of scope registration
   # scope level 2
      #method call gcd
      addi $sp, $sp, -8#arguments
      # b
      addi $s1, $fp, -4
      #param: b offset -4
      lw $s1, 0($s1)
      #saving previous value
      sw $a0, 0($sp)
      #end saving
     move $a0, $s1
       # a
       addi $s1, $fp, -8
       #param: a offset -8
       lw $s1, 0($s1)
       # b
       addi $s2, $fp, -4
       #param: b offset -4
       lw $s2, 0($s2)
      rem $t1, $s1, $s2
      #saving previous value
      sw $a1, 4($sp)
      #end saving
     move $a1, $t1
     jal gcd
      lw $a1, 0($sp)
      lw $a0, 4($sp)
      addi $sp, $sp, 8
      #end method callgcd
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

    la $t0, string_0
  move $a0, $t0
  li $v0, 4
  syscall
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
#epilog for gcd
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
#end of epilog for gcd
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
   # aaaaa
   la $s0, aaaaa
   lw $s0, 0($s0)
   #var x
   la $s1, x
  sw $s0, 0($s1)
#termino assignment...
   # bbbbb1
   la $s0, bbbbb1
   lw $s0, 0($s0)
   #var y
   la $s1, y
  sw $s0, 0($s1)
#termino assignment...
    #method call gcd
    addi $sp, $sp, -8#arguments
    # x
    la $s0, x
    lw $s0, 0($s0)
    #saving previous value
    sw $a0, 0($sp)
    #end saving
   move $a0, $s0
    # y
    la $s0, y
    lw $s0, 0($s0)
    #saving previous value
    sw $a1, 4($sp)
    #end saving
   move $a1, $s0
   jal gcd
    lw $a1, 0($sp)
    lw $a0, 4($sp)
    addi $sp, $sp, 8
    #end method callgcd
   #var z
   la $s0, z
  sw $v0, 0($s0)
#termino assignment...
   # z
   la $s0, z
   lw $s0, 0($s0)
  move $a0, $s0
  li $v0, 1
  syscall
    la $t0, string_0
  move $a0, $t0
  li $v0, 4
  syscall
 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 0
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


