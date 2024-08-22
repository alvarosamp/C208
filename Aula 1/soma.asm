.text
#add $t3,$t2,$t1 # Fazendo a soma -> t3 = t2+t1
#sub $t3,$t2,$t1
#mult $t2,$t3 # o resultado vai aparece rem 'lo' dentro do 'registers'
div $t2,$t3 # O resultado tabem vai para 'lo' so que em hexadecimal
# Em uma divisao o quociente é o 'lo', e o resto é o 'hi'