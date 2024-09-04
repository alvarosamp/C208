.data
entrou: .asciiz "Entrou no if \n"
nao : .asciiz "Não entrou no if"

.text
li $t1, 0x10
li $t2, 0x10

beq $t1, $t2, igual #igual é uma label
la $a0, nao
li $v0, 4
syscall
j fim #Desvio incondicional -> Tipo um else
igual:
la $a0, entrou
li $v0, 4
syscall

fim:li $v0,10
	syscall
