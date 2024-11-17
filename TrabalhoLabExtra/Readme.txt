Início da simulação
-------------------------
Passo 1
Instrução na PC=0x00400000 0x2408FEC0
ADDIU $8 = $0 + -320 - -320
Registradores relevantes
 $t0 ($8) = -320
 $t1 ($9) = 0
 PC = 0x00400004
-------------------------
Passo 2
Instrução na PC=0x00400004 0x2409FFB0
ADDIU $9 = $0 + -80 - -80
Registradores relevantes
 $t0 ($8) = -320
 $t1 ($9) = -80
 PC = 0x00400008
-------------------------
Passo 3
Instrução na PC=0x00400008 0x01094023
SUBU $8 = $8 - $9 - -240
Registradores relevantes
 $t0 ($8) = -240
 $t1 ($9) = -80
 PC = 0x0040000C
-------------------------
Passo 4
Instrução na PC=0x0040000C 0xAC080000
SW Mem[0] = $8 - -240
Registradores relevantes
 $t0 ($8) = -240
 $t1 ($9) = -80
 PC = 0x00400010
-------------------------
Passo 5
Instrução na PC=0x00400010 0x1500FFFD
BNE Offset extraído = -3
BNE $8 != $0, jump para 0x00400008
Registradores relevantes
 $t0 ($8) = -240
 $t1 ($9) = -80
 PC = 0x00400008
-------------------------
Passo 6
Instrução na PC=0x00400008 0x01094023
SUBU $8 = $8 - $9 - -160
Registradores relevantes
 $t0 ($8) = -160
 $t1 ($9) = -80
 PC = 0x0040000C
-------------------------
Passo 7
Instrução na PC=0x0040000C 0xAC080000
SW Mem[0] = $8 - -160
Registradores relevantes
 $t0 ($8) = -160
 $t1 ($9) = -80
 PC = 0x00400010
-------------------------
Passo 8
Instrução na PC=0x00400010 0x1500FFFD
BNE Offset extraído = -3
BNE $8 != $0, jump para 0x00400008
Registradores relevantes
 $t0 ($8) = -160
 $t1 ($9) = -80
 PC = 0x00400008
-------------------------
Passo 9
Instrução na PC=0x00400008 0x01094023
SUBU $8 = $8 - $9 - -80
Registradores relevantes
 $t0 ($8) = -80
 $t1 ($9) = -80
 PC = 0x0040000C
-------------------------
Passo 10
Instrução na PC=0x0040000C 0xAC080000
SW Mem[0] = $8 - -80
Registradores relevantes
 $t0 ($8) = -80
 $t1 ($9) = -80
 PC = 0x00400010
-------------------------
Passo 11
Instrução na PC=0x00400010 0x1500FFFD
BNE Offset extraído = -3
BNE $8 != $0, jump para 0x00400008
Registradores relevantes
 $t0 ($8) = -80
 $t1 ($9) = -80
 PC = 0x00400008
-------------------------
Passo 12
Instrução na PC=0x00400008 0x01094023
SUBU $8 = $8 - $9 - 0
Registradores relevantes
 $t0 ($8) = 0
 $t1 ($9) = -80
 PC = 0x0040000C
-------------------------
$t0 atingiu zero. Encerrando a simulação.
Estado Final
$t0 = 0
$t1 = -80
Mem[0] = -80
