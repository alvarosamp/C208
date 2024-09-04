.data 
frase1: .asciiz "A media eh: "
frase2: .asciiz "Entre com o primeiro numero"
frase3: .asciiz "Entre com o segundo numero"
.text

la $a0, frase2
li $v0, 4 #Carrega o print string
syscall

#salvando a variavel 1
li $v0,5
syscall 
add $t1,$v0,$0

#Imprimindo a frase 2
la $a0, frase3
li $v0, 4 #Carrega o print string
syscall

#salvando a variavel 2
li $v0,5
syscall 
add $t2,$v0,$0

#calculando a média
add $t3, $t1, $t2  # $t3 = $t1 + $t2
li $t4, 2          # Carregar o divisor 2 em $t4
div $t3, $t4       # Dividir $t3 por $t4 (resultado em lo, resto em hi)
mflo $t5           # Mover o quociente (média) para $t5


#imprimindo o valor da media
#Imprimindo a frase 1
la $a0, frase1
li $v0, 4 #Carrega o print string
syscall

#Deslocando t4 para a0
add $a0,$t5, $0 # deslocando o valor para a0
li $v0, 1
syscall

