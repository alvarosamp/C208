.data 
frase1: .asciiz "Entre com um valor inteiro"
frase2: .asciiz "O valor digitado foi: "
.text
la $a0, frase1
#  Como a frase 1 é uma label e uma label é um endereço, ele paga a string e joga la
li $v0, 4 #Carrega o print string
syscall 

#salvando uma variavel
li $v0,5 # Lendo uma variavel inteira
syscall
add $t1, $v0,$0

#Imprimindo o numero que foi inserido
la $a0,frase2
li $v0, 4
syscall

add $a0,$t1, $0 # deslocando o valor para a0
li $v0, 1
syscall