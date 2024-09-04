#  a = (b+10) + (c-5) - ( d- e) -> Resolva essa equação
.text
li $s0, 10
li $s1, 20
li $t2, 40
li $s3, 50
li $s4, 30

addi $t1, $s1, 10
addi $t2,$s2, -5
sub $t3, $s3, $s4
add $t1, $t1, $t2,
sub $s0, $t1, $t3
