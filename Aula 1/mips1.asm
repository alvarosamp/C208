#Exemplo 6
.data
#cada ou ascii é armazenado sequencialmente, começando no primeiro endereço de memoria
cadeia : .ascii "abcde"
	 .word 0x345 #Uma word sempre OCUPA 4 BYTES. Quando nao temos 4bytes livres ela pula para o proximo, com 4. Mesmo tendo espaço em branco depois precisamos mudar de byte
octeto: .byte 0xff #
string: .asciiz "teste"

