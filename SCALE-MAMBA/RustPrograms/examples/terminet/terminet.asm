clear_registers
ldint r6, 1000
ldint r7, 1000
newc r4, r6
newint r5, r7
ldint r6, 131072
newint r2, r6
print_char 10 # converted function call directly to asm
print_char 35 # converted function call directly to asm
print_char 32 # converted function call directly to asm
print_char 77 # converted function call directly to asm
print_char 101 # converted function call directly to asm
print_char 97 # converted function call directly to asm
print_char 110 # converted function call directly to asm
print_char 32 # converted function call directly to asm
print_char 65 # converted function call directly to asm
print_char 108 # converted function call directly to asm
print_char 103 # converted function call directly to asm
print_char 111 # converted function call directly to asm
print_char 114 # converted function call directly to asm
print_char 105 # converted function call directly to asm
print_char 116 # converted function call directly to asm
print_char 104 # converted function call directly to asm
print_char 109 # converted function call directly to asm
print_char 32 # converted function call directly to asm
print_char 102 # converted function call directly to asm
print_char 111 # converted function call directly to asm
print_char 114 # converted function call directly to asm
print_char 32 # converted function call directly to asm
print_char 84 # converted function call directly to asm
print_char 69 # converted function call directly to asm
print_char 82 # converted function call directly to asm
print_char 77 # converted function call directly to asm
print_char 73 # converted function call directly to asm
print_char 78 # converted function call directly to asm
print_char 69 # converted function call directly to asm
print_char 84 # converted function call directly to asm
print_char 32 # converted function call directly to asm
print_char 40 # converted function call directly to asm
print_char 101 # converted function call directly to asm
print_char 97 # converted function call directly to asm
print_char 115 # converted function call directly to asm
print_char 121 # converted function call directly to asm
print_char 32 # converted function call directly to asm
print_char 105 # converted function call directly to asm
print_char 110 # converted function call directly to asm
print_char 112 # converted function call directly to asm
print_char 117 # converted function call directly to asm
print_char 116 # converted function call directly to asm
print_char 41 # converted function call directly to asm
print_char 10 # converted function call directly to asm
print_char 10 # converted function call directly to asm
ldint r7, 5
ldint r6, 1
pushint r7 # converted function call directly to asm
lf 125 # converted function call directly to asm
popint r3 # converted function call directly to asm
news r0, r6 # converted function call directly to asm
print_int r1 # converted function call directly to asm
print_char 10 # converted function call directly to asm
ldint r6, 0
convregsreg sr0, r6 # converted function call directly to asm
ldint r6, 0
ldint r7, 1
private_input s0, r7, r6 # converted function call directly to asm
convsintsreg sr1, s0 # converted function call directly to asm
addsint sr0, sr0, sr1 # converted function call directly to asm
ldint r6, 0
ldint r7, 2
private_input s0, r7, r6 # converted function call directly to asm
convsintsreg sr1, s0 # converted function call directly to asm
addsint sr0, sr0, sr1 # converted function call directly to asm
ldint r6, 0
ldint r7, 3
private_input s0, r7, r6 # converted function call directly to asm
convsintsreg sr1, s0 # converted function call directly to asm
addsint sr0, sr0, sr1 # converted function call directly to asm
ldint r6, 0
ldint r7, 4
private_input s0, r7, r6 # converted function call directly to asm
convsintsreg sr1, s0 # converted function call directly to asm
addsint sr0, sr0, sr1 # converted function call directly to asm
ldint r6, 0
ldint r7, 5
private_input s0, r7, r6 # converted function call directly to asm
convsintsreg sr1, s0 # converted function call directly to asm
addsint sr0, sr0, sr1 # converted function call directly to asm
pushsint sr0 # converted function call directly to asm
gc 125 # converted function call directly to asm
popsint sr0 # converted function call directly to asm
opensint r6, sr0 # converted function call directly to asm
pushint r6 # converted function call directly to asm
pushint r3 # converted function call directly to asm
lf 122 # converted function call directly to asm
popint r6 # converted function call directly to asm
convregsreg sr0, r6 # converted function call directly to asm
pushsint sr0 # converted function call directly to asm
gc 124 # converted function call directly to asm
popsint sr0 # converted function call directly to asm
convsregsint s0, sr0 # converted function call directly to asm
stmsi s0, r0 # converted function call directly to asm
ldint r6, 1
news r6, r6 # converted function call directly to asm
ldmsi s0, r0 # converted function call directly to asm
stmsi s0, r6 # converted function call directly to asm
ldint r7, 0
ldint r8, 0
ldint r9, 1
mprivate_output r6, r9, r8, r7 # converted function call directly to asm
deletes r6 # converted function call directly to asm
ldint r7, 1
addint r1, r1, r7
jmpne r1, 4881, -55 # br_if
deletes r0 # converted function call directly to asm
