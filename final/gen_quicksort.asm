.data
array: .space 120 # 30 integers
arraySize: .word 5
#special data
display: .word 0:9
string_0: .asciiz "\n"


.text
quicksort_class_not_a_function:
j main

___:
#prolog for ___
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
#end of prolog for ___
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
    # i
    la $s0, display
    addi $s0, $s0, 4
    lw $s0, 0($s0)
    addi $s0, $s0, 0
    #local: i offset 0 level 1
    lw $s0, 0($s0)
    # arraySize
    la $s1, arraySize
    lw $s1, 0($s1)
   slt $t0, $s0, $s1
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
   continue_point_0: 
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
  j for_label_0
  out_of_for_0:
 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 4
 la $t1, display
 lw $t2, 0($sp)
 addi $sp, $sp, 4
 sw $t2, 4($t1)
 #end of scope unregistration
# end of function body code
function_end_0:
#epilog for ___
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
#end of epilog for ___
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
 #saving parameters because of method call
 addi $sp, $sp, -16
 sw $a0, 0($sp)
 sw $a1, 4($sp)
 sw $a2, 8($sp)
 sw $a3, 12($sp)
 #end saving parameters because of method call
   #method call ___
   addi $sp, $sp, 0#arguments
  jal ___
   addi $sp, $sp, 0
   #end method call___
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
   #method call quicksort
   addi $sp, $sp, -8#arguments
   li $t0, 0
   #saving previous value
   sw $a0, 0($sp)
   #end saving
  move $a0, $t0
    # arraySize
    la $s0, arraySize
    lw $s0, 0($s0)
    li $t0, 1
   sub $t0, $s0, $t0
   #saving previous value
   sw $a1, 4($sp)
   #end saving
  move $a1, $t0
  jal quicksort
   lw $a1, 0($sp)
   lw $a0, 4($sp)
   addi $sp, $sp, 8
   #end method callquicksort
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
   #method call print_array
   addi $sp, $sp, 0#arguments
  jal print_array
   addi $sp, $sp, 0
   #end method callprint_array
 #restoring parameters because of method call
 lw $a0, 0($sp)
 lw $a1, 4($sp)
 lw $a2, 8($sp)
 lw $a3, 12($sp)
 addi $sp, $sp, 16
 #end restoring parameters because of method call
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


particionar:
#prolog for particionar
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
#end of prolog for particionar
# function body code
 #generating scope registration logic...
 la $t0, display
 lw $t1, 4($t0)
 addi $sp, $sp, -4
 sw $t1, 0($sp)
 addi $sp, $sp, -12   #reservar el espacio para el scope
 sw $sp, 4($t0)
 #end of scope registration
 # scope level 1
   # array
   la $s0, array
    # izq
    addi $s1, $fp, -8
    #param: izq offset -8
    lw $s1, 0($s1)
    sll $s1, $s1, 2# multiply by 4
   add $s0, $s0, $s1
   lw $s0, 0($s0)
   #var p
   la $s2, display
   addi $s2, $s2, 4
   lw $s2, 0($s2)
   addi $s2, $s2, 8
   #local: p offset 0 level 1
  sw $s0, 0($s2)
#termino assignment...
   # izq
   addi $s0, $fp, -8
   #param: izq offset -8
   lw $s0, 0($s0)
   #var i
   la $s2, display
   addi $s2, $s2, 4
   lw $s2, 0($s2)
   addi $s2, $s2, 4
   #local: i offset 4 level 1
  sw $s0, 0($s2)
#termino assignment...
   # der
   addi $s0, $fp, -4
   #param: der offset -4
   lw $s0, 0($s0)
   #var j
   la $s2, display
   addi $s2, $s2, 4
   lw $s2, 0($s2)
   addi $s2, $s2, 0
   #local: j offset 8 level 1
  sw $s0, 0($s2)
#termino assignment...
  while_label_0:
    # i
    la $s0, display
    addi $s0, $s0, 4
    lw $s0, 0($s0)
    addi $s0, $s0, 4
    #local: i offset 4 level 1
    lw $s0, 0($s0)
    # j
    la $s2, display
    addi $s2, $s2, 4
    lw $s2, 0($s2)
    addi $s2, $s2, 0
    #local: j offset 8 level 1
    lw $s2, 0($s2)
   slt $t0, $s0, $s2
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
    while_label_1:
       # array
       la $s0, array
        # i
        la $s2, display
        addi $s2, $s2, 4
        lw $s2, 0($s2)
        addi $s2, $s2, 4
        #local: i offset 4 level 1
        lw $s2, 0($s2)
        sll $s2, $s2, 2# multiply by 4
       add $s0, $s0, $s2
       lw $s0, 0($s0)
       # p
       la $s3, display
       addi $s3, $s3, 4
       lw $s3, 0($s3)
       addi $s3, $s3, 8
       #local: p offset 0 level 1
       lw $s3, 0($s3)
      slt $t1, $s3, $s0
       # i
       la $s0, display
       addi $s0, $s0, 4
       lw $s0, 0($s0)
       addi $s0, $s0, 4
       #local: i offset 4 level 1
       lw $s0, 0($s0)
       # der
       addi $s3, $fp, -4
       #param: der offset -4
       lw $s3, 0($s3)
      slt $t2, $s0, $s3
     beq $t1, $zero, false_0
     beq $t2, $zero, false_0
     li $t1, 1
     j end_0
     false_0:
     li $t1, 0
     end_0: 
     beq $t1, $zero, out_of_while_1
     #generating scope registration logic...
     la $t2, display
     lw $t3, 12($t2)
     addi $sp, $sp, -4
     sw $t3, 0($sp)
     addi $sp, $sp, 0   #reservar el espacio para el scope
     sw $sp, 12($t2)
     #end of scope registration
     # scope level 3
        # i
        la $s0, display
        addi $s0, $s0, 4
        lw $s0, 0($s0)
        addi $s0, $s0, 4
        #local: i offset 4 level 1
        lw $s0, 0($s0)
        li $t2, 1
       add $t2, $s0, $t2
       #var i
       la $s0, display
       addi $s0, $s0, 4
       lw $s0, 0($s0)
       addi $s0, $s0, 4
       #local: i offset 4 level 1
      sw $t2, 0($s0)
#termino assignment...
     # end of scope level 3
     #starting scope unregistration code...
     addi $sp, $sp, 0
     la $t2, display
     lw $t3, 0($sp)
     addi $sp, $sp, 4
     sw $t3, 12($t2)
     #end of scope unregistration
    j while_label_1
    out_of_while_1:
    while_label_2:
       # array
       la $s0, array
        # j
        la $s3, display
        addi $s3, $s3, 4
        lw $s3, 0($s3)
        addi $s3, $s3, 0
        #local: j offset 8 level 1
        lw $s3, 0($s3)
        sll $s3, $s3, 2# multiply by 4
       add $s0, $s0, $s3
       lw $s0, 0($s0)
       # p
       la $s4, display
       addi $s4, $s4, 4
       lw $s4, 0($s4)
       addi $s4, $s4, 8
       #local: p offset 0 level 1
       lw $s4, 0($s4)
      sle $t2, $s0, $s4
       # j
       la $s0, display
       addi $s0, $s0, 4
       lw $s0, 0($s0)
       addi $s0, $s0, 0
       #local: j offset 8 level 1
       lw $s0, 0($s0)
       # izq
       addi $s4, $fp, -8
       #param: izq offset -8
       lw $s4, 0($s4)
      slt $t3, $s4, $s0
     beq $t2, $zero, false_1
     beq $t3, $zero, false_1
     li $t2, 1
     j end_1
     false_1:
     li $t2, 0
     end_1: 
     beq $t2, $zero, out_of_while_2
     #generating scope registration logic...
     la $t3, display
     lw $t4, 12($t3)
     addi $sp, $sp, -4
     sw $t4, 0($sp)
     addi $sp, $sp, 0   #reservar el espacio para el scope
     sw $sp, 12($t3)
     #end of scope registration
     # scope level 3
        # j
        la $s0, display
        addi $s0, $s0, 4
        lw $s0, 0($s0)
        addi $s0, $s0, 0
        #local: j offset 8 level 1
        lw $s0, 0($s0)
        li $t3, 1
       sub $t3, $s0, $t3
       #var j
       la $s0, display
       addi $s0, $s0, 4
       lw $s0, 0($s0)
       addi $s0, $s0, 0
       #local: j offset 8 level 1
      sw $t3, 0($s0)
#termino assignment...
     # end of scope level 3
     #starting scope unregistration code...
     addi $sp, $sp, 0
     la $t3, display
     lw $t4, 0($sp)
     addi $sp, $sp, 4
     sw $t4, 12($t3)
     #end of scope unregistration
    j while_label_2
    out_of_while_2:
      # i
      la $s0, display
      addi $s0, $s0, 4
      lw $s0, 0($s0)
      addi $s0, $s0, 4
      #local: i offset 4 level 1
      lw $s0, 0($s0)
      # izq
      addi $s4, $fp, -8
      #param: izq offset -8
      lw $s4, 0($s4)
     seq $t3, $s0, $s4
      # j
      la $s0, display
      addi $s0, $s0, 4
      lw $s0, 0($s0)
      addi $s0, $s0, 0
      #local: j offset 8 level 1
      lw $s0, 0($s0)
      # i
      la $s4, display
      addi $s4, $s4, 4
      lw $s4, 0($s4)
      addi $s4, $s4, 4
      #local: i offset 4 level 1
      lw $s4, 0($s4)
     seq $t4, $s0, $s4
    beq $t3, $zero, false_2
    beq $t4, $zero, false_2
    li $t3, 1
    j end_2
    false_2:
    li $t3, 0
    end_2: 
    beq $t3, $zero, else_label_0
     #generating scope registration logic...
     la $t4, display
     lw $t5, 12($t4)
     addi $sp, $sp, -4
     sw $t5, 0($sp)
     addi $sp, $sp, 0   #reservar el espacio para el scope
     sw $sp, 12($t4)
     #end of scope registration
     # scope level 3
     #saving parameters because of method call
     addi $sp, $sp, -16
     sw $a0, 0($sp)
     sw $a1, 4($sp)
     sw $a2, 8($sp)
     sw $a3, 12($sp)
     #end saving parameters because of method call
       #method call quicksort
       addi $sp, $sp, -8#arguments
        # izq
        addi $s0, $fp, -8
        #param: izq offset -8
        lw $s0, 0($s0)
        li $t4, 1
       add $t4, $s0, $t4
       #saving previous value
       sw $a0, 0($sp)
       #end saving
      move $a0, $t4
       # der
       addi $s0, $fp, -4
       #param: der offset -4
       lw $s0, 0($s0)
       #saving previous value
       sw $a1, 4($sp)
       #end saving
      move $a1, $s0
      jal quicksort
       lw $a1, 0($sp)
       lw $a0, 4($sp)
       addi $sp, $sp, 8
       #end method callquicksort
     #restoring parameters because of method call
     lw $a0, 0($sp)
     lw $a1, 4($sp)
     lw $a2, 8($sp)
     lw $a3, 12($sp)
     addi $sp, $sp, 16
     #end restoring parameters because of method call
     # end of scope level 3
     #starting scope unregistration code...
     addi $sp, $sp, 0
     la $t4, display
     lw $t5, 0($sp)
     addi $sp, $sp, 4
     sw $t5, 12($t4)
     #end of scope unregistration

    else_label_0:
      # i
      la $s0, display
      addi $s0, $s0, 4
      lw $s0, 0($s0)
      addi $s0, $s0, 4
      #local: i offset 4 level 1
      lw $s0, 0($s0)
      # der
      addi $s4, $fp, -4
      #param: der offset -4
      lw $s4, 0($s4)
     seq $t3, $s0, $s4
      # j
      la $s0, display
      addi $s0, $s0, 4
      lw $s0, 0($s0)
      addi $s0, $s0, 0
      #local: j offset 8 level 1
      lw $s0, 0($s0)
      # i
      la $s4, display
      addi $s4, $s4, 4
      lw $s4, 0($s4)
      addi $s4, $s4, 4
      #local: i offset 4 level 1
      lw $s4, 0($s4)
     seq $t4, $s0, $s4
    beq $t3, $zero, false_3
    beq $t4, $zero, false_3
    li $t3, 1
    j end_3
    false_3:
    li $t3, 0
    end_3: 
    beq $t3, $zero, else_label_1
     #generating scope registration logic...
     la $t4, display
     lw $t5, 12($t4)
     addi $sp, $sp, -4
     sw $t5, 0($sp)
     addi $sp, $sp, 0   #reservar el espacio para el scope
     sw $sp, 12($t4)
     #end of scope registration
     # scope level 3
     #saving parameters because of method call
     addi $sp, $sp, -16
     sw $a0, 0($sp)
     sw $a1, 4($sp)
     sw $a2, 8($sp)
     sw $a3, 12($sp)
     #end saving parameters because of method call
       #method call quicksort
       addi $sp, $sp, -8#arguments
       # izq
       addi $s0, $fp, -8
       #param: izq offset -8
       lw $s0, 0($s0)
       #saving previous value
       sw $a0, 0($sp)
       #end saving
      move $a0, $s0
        # der
        addi $s0, $fp, -4
        #param: der offset -4
        lw $s0, 0($s0)
        li $t4, 1
       sub $t4, $s0, $t4
       #saving previous value
       sw $a1, 4($sp)
       #end saving
      move $a1, $t4
      jal quicksort
       lw $a1, 0($sp)
       lw $a0, 4($sp)
       addi $sp, $sp, 8
       #end method callquicksort
     #restoring parameters because of method call
     lw $a0, 0($sp)
     lw $a1, 4($sp)
     lw $a2, 8($sp)
     lw $a3, 12($sp)
     addi $sp, $sp, 16
     #end restoring parameters because of method call
     # end of scope level 3
     #starting scope unregistration code...
     addi $sp, $sp, 0
     la $t4, display
     lw $t5, 0($sp)
     addi $sp, $sp, 4
     sw $t5, 12($t4)
     #end of scope unregistration

    else_label_1:
     # i
     la $s0, display
     addi $s0, $s0, 4
     lw $s0, 0($s0)
     addi $s0, $s0, 4
     #local: i offset 4 level 1
     lw $s0, 0($s0)
     # j
     la $s4, display
     addi $s4, $s4, 4
     lw $s4, 0($s4)
     addi $s4, $s4, 0
     #local: j offset 8 level 1
     lw $s4, 0($s4)
    slt $t3, $s0, $s4
    beq $t3, $zero, else_label_2
     #generating scope registration logic...
     la $t4, display
     lw $t5, 12($t4)
     addi $sp, $sp, -4
     sw $t5, 0($sp)
     addi $sp, $sp, 0   #reservar el espacio para el scope
     sw $sp, 12($t4)
     #end of scope registration
     # scope level 3
     #saving parameters because of method call
     addi $sp, $sp, -16
     sw $a0, 0($sp)
     sw $a1, 4($sp)
     sw $a2, 8($sp)
     sw $a3, 12($sp)
     #end saving parameters because of method call
       #method call swap
       addi $sp, $sp, -8#arguments
       # i
       la $s0, display
       addi $s0, $s0, 4
       lw $s0, 0($s0)
       addi $s0, $s0, 4
       #local: i offset 4 level 1
       lw $s0, 0($s0)
       #saving previous value
       sw $a0, 0($sp)
       #end saving
      move $a0, $s0
       # j
       la $s0, display
       addi $s0, $s0, 4
       lw $s0, 0($s0)
       addi $s0, $s0, 0
       #local: j offset 8 level 1
       lw $s0, 0($s0)
       #saving previous value
       sw $a1, 4($sp)
       #end saving
      move $a1, $s0
      jal swap
       lw $a1, 0($sp)
       lw $a0, 4($sp)
       addi $sp, $sp, 8
       #end method callswap
     #restoring parameters because of method call
     lw $a0, 0($sp)
     lw $a1, 4($sp)
     lw $a2, 8($sp)
     lw $a3, 12($sp)
     addi $sp, $sp, 16
     #end restoring parameters because of method call
     # end of scope level 3
     #starting scope unregistration code...
     addi $sp, $sp, 0
     la $t4, display
     lw $t5, 0($sp)
     addi $sp, $sp, 4
     sw $t5, 12($t4)
     #end of scope unregistration

    else_label_2:
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 0
   la $t3, display
   lw $t4, 0($sp)
   addi $sp, $sp, 4
   sw $t4, 8($t3)
   #end of scope unregistration
  j while_label_0
  out_of_while_0:
   # j
   la $s0, display
   addi $s0, $s0, 4
   lw $s0, 0($s0)
   addi $s0, $s0, 0
   #local: j offset 8 level 1
   lw $s0, 0($s0)
  move $v0, $s0
  #unregisterAll ...
 #starting scope unregistration code...
 addi $sp, $sp, 12
 la $t3 , display
 lw  $t4 , 0($sp)
 addi $sp, $sp, 4
 sw $t4, 4($t3)
 #end of scope unregistration


  #termino unregisterAll
  j function_end_2
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

 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 12
 la $t3, display
 lw $t4, 0($sp)
 addi $sp, $sp, 4
 sw $t4, 4($t3)
 #end of scope unregistration
# end of function body code
function_end_2:
#epilog for particionar
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
#end of epilog for particionar
jr $ra


print_array:
#prolog for print_array
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
#end of prolog for print_array
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
    # arraySize
    la $s1, arraySize
    lw $s1, 0($s1)
   slt $t0, $s0, $s1
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
      la $t1, string_0
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
function_end_3:
#epilog for print_array
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
#end of epilog for print_array
jr $ra


quicksort:
#prolog for quicksort
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
#end of prolog for quicksort
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
   # izq
   addi $s0, $fp, -8
   #param: izq offset -8
   lw $s0, 0($s0)
   # der
   addi $s1, $fp, -4
   #param: der offset -4
   lw $s1, 0($s1)
  slt $t0, $s0, $s1
  beq $t0, $zero, else_label_3
   #generating scope registration logic...
   la $t1, display
   lw $t2, 8($t1)
   addi $sp, $sp, -4
   sw $t2, 0($sp)
   addi $sp, $sp, -4   #reservar el espacio para el scope
   sw $sp, 8($t1)
   #end of scope registration
   # scope level 2
      #method call particionar
      addi $sp, $sp, -8#arguments
      # izq
      addi $s0, $fp, -8
      #param: izq offset -8
      lw $s0, 0($s0)
      #saving previous value
      sw $a0, 0($sp)
      #end saving
     move $a0, $s0
      # der
      addi $s0, $fp, -4
      #param: der offset -4
      lw $s0, 0($s0)
      #saving previous value
      sw $a1, 4($sp)
      #end saving
     move $a1, $s0
     jal particionar
      lw $a1, 0($sp)
      lw $a0, 4($sp)
      addi $sp, $sp, 8
      #end method callparticionar
     #var k
     la $s0, display
     addi $s0, $s0, 8
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: k offset 0 level 2
    sw $v0, 0($s0)
#termino assignment...
   #saving parameters because of method call
   addi $sp, $sp, -16
   sw $a0, 0($sp)
   sw $a1, 4($sp)
   sw $a2, 8($sp)
   sw $a3, 12($sp)
   #end saving parameters because of method call
     #method call quicksort
     addi $sp, $sp, -8#arguments
     # izq
     addi $s0, $fp, -8
     #param: izq offset -8
     lw $s0, 0($s0)
     #saving previous value
     sw $a0, 0($sp)
     #end saving
    move $a0, $s0
     # k
     la $s0, display
     addi $s0, $s0, 8
     lw $s0, 0($s0)
     addi $s0, $s0, 0
     #local: k offset 0 level 2
     lw $s0, 0($s0)
     #saving previous value
     sw $a1, 4($sp)
     #end saving
    move $a1, $s0
    jal quicksort
     lw $a1, 0($sp)
     lw $a0, 4($sp)
     addi $sp, $sp, 8
     #end method callquicksort
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
     #method call quicksort
     addi $sp, $sp, -8#arguments
      # k
      la $s0, display
      addi $s0, $s0, 8
      lw $s0, 0($s0)
      addi $s0, $s0, 0
      #local: k offset 0 level 2
      lw $s0, 0($s0)
      li $t1, 1
     add $t1, $s0, $t1
     #saving previous value
     sw $a0, 0($sp)
     #end saving
    move $a0, $t1
     # der
     addi $s0, $fp, -4
     #param: der offset -4
     lw $s0, 0($s0)
     #saving previous value
     sw $a1, 4($sp)
     #end saving
    move $a1, $s0
    jal quicksort
     lw $a1, 0($sp)
     lw $a0, 4($sp)
     addi $sp, $sp, 8
     #end method callquicksort
   #restoring parameters because of method call
   lw $a0, 0($sp)
   lw $a1, 4($sp)
   lw $a2, 8($sp)
   lw $a3, 12($sp)
   addi $sp, $sp, 16
   #end restoring parameters because of method call
   # end of scope level 2
   #starting scope unregistration code...
   addi $sp, $sp, 4
   la $t1, display
   lw $t2, 0($sp)
   addi $sp, $sp, 4
   sw $t2, 8($t1)
   #end of scope unregistration

  else_label_3:
 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 0
 la $t0, display
 lw $t1, 0($sp)
 addi $sp, $sp, 4
 sw $t1, 4($t0)
 #end of scope unregistration
# end of function body code
function_end_4:
#epilog for quicksort
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
#end of epilog for quicksort
jr $ra


swap:
#prolog for swap
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
#end of prolog for swap
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
   # array
   la $s0, array
    # i
    addi $s1, $fp, -8
    #param: i offset -8
    lw $s1, 0($s1)
    sll $s1, $s1, 2# multiply by 4
   add $s0, $s0, $s1
   lw $s0, 0($s0)
   #var aux
   la $s2, display
   addi $s2, $s2, 4
   lw $s2, 0($s2)
   addi $s2, $s2, 0
   #local: aux offset 0 level 1
  sw $s0, 0($s2)
#termino assignment...
   # array
   la $s0, array
    # j
    addi $s2, $fp, -4
    #param: j offset -4
    lw $s2, 0($s2)
    sll $s2, $s2, 2# multiply by 4
   add $s0, $s0, $s2
   lw $s0, 0($s0)
   #var array
   la $s3, array
    # i
    addi $s4, $fp, -8
    #param: i offset -8
    lw $s4, 0($s4)
    sll $s4, $s4, 2# multiply by 4
   add $s3, $s3, $s4
  sw $s0, 0($s3)
#termino assignment...
   # aux
   la $s0, display
   addi $s0, $s0, 4
   lw $s0, 0($s0)
   addi $s0, $s0, 0
   #local: aux offset 0 level 1
   lw $s0, 0($s0)
   #var array
   la $s3, array
    # j
    addi $s5, $fp, -4
    #param: j offset -4
    lw $s5, 0($s5)
    sll $s5, $s5, 2# multiply by 4
   add $s3, $s3, $s5
  sw $s0, 0($s3)
#termino assignment...
 # end of scope level 1
 #starting scope unregistration code...
 addi $sp, $sp, 4
 la $t0, display
 lw $t1, 0($sp)
 addi $sp, $sp, 4
 sw $t1, 4($t0)
 #end of scope unregistration
# end of function body code
function_end_5:
#epilog for swap
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
#end of epilog for swap
jr $ra


