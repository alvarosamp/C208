#lembrar que os numeros estão em hexadecimal
.data
n1: .byte 0x10
n2: .byte 0x20
media: .byte
.text
lb $t1,n1 #Carrega n1 em $t1
lb $t2, n2 #Carrega n2 em $t2
add $t3, $t1, $t2
addi $t4,$0, 2 #Move 2 para $t4 No caso vai somar 2+0 e depois podemos dividir. Devemos definir um numero como esse valor
div $t3, $t4 #fazendo a divisao
mflo $t5 #Resultado da conta
sb $t5, media #Guardando o resultado na memoria


#Outra forma de fazer a divisao
#srl $t5, $t3, 1
#sb $t5, media