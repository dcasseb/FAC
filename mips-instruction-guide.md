# Complete MIPS Instruction Set Reference Guide

## Table of Contents
1. [Arithmetic Instructions](#1-arithmetic-instructions)
2. [Logical Instructions](#2-logical-instructions)
3. [Data Transfer Instructions](#3-data-transfer-instructions)
4. [Branch Instructions](#4-branch-instructions)
5. [Jump Instructions](#5-jump-instructions)
6. [Comparison Instructions](#6-comparison-instructions)
7. [Shift Instructions](#7-shift-instructions)
8. [Multiplication/Division Instructions](#8-multiplicationdivision-instructions)
9. [Pseudo Instructions](#9-pseudo-instructions)

## 1. Arithmetic Instructions

### ADD (Add)
```mips
add $rd, $rs, $rt    # $rd = $rs + $rt
```
- **Use Cases:**
  - Integer addition
  - Combining values
  - Incrementing by variable amounts
- **Example:**
```mips
add $t0, $t1, $t2    # Add contents of $t1 and $t2, store in $t0
```

### ADDI (Add Immediate)
```mips
addi $rt, $rs, imm   # $rt = $rs + immediate
```
- **Use Cases:**
  - Adding constants
  - Incrementing by fixed amounts
  - Array indexing
- **Example:**
```mips
addi $t0, $t0, 1     # Increment $t0 by 1
addi $t1, $t2, -5    # Subtract 5 from $t2, store in $t1
```

### ADDU (Add Unsigned)
```mips
addu $rd, $rs, $rt   # $rd = $rs + $rt (unsigned)
```
- **Use Cases:**
  - Adding unsigned numbers
  - When overflow checking isn't needed
- **Example:**
```mips
addu $t0, $t1, $t2   # Add unsigned values
```

### SUB (Subtract)
```mips
sub $rd, $rs, $rt    # $rd = $rs - $rt
```
- **Use Cases:**
  - Integer subtraction
  - Finding differences
  - Decreasing values
- **Example:**
```mips
sub $t0, $t1, $t2    # Subtract $t2 from $t1, store in $t0
```

## 2. Logical Instructions

### AND (Bitwise AND)
```mips
and $rd, $rs, $rt    # $rd = $rs & $rt
```
- **Use Cases:**
  - Bit masking
  - Testing bit patterns
  - Clearing specific bits
- **Example:**
```mips
and $t0, $t1, $t2    # Bitwise AND of $t1 and $t2
andi $t0, $t1, 0xF   # Keep only lower 4 bits
```

### OR (Bitwise OR)
```mips
or $rd, $rs, $rt     # $rd = $rs | $rt
```
- **Use Cases:**
  - Setting specific bits
  - Combining bit patterns
  - Flag operations
- **Example:**
```mips
or $t0, $t1, $t2     # Bitwise OR of $t1 and $t2
ori $t0, $t1, 0x1    # Set lowest bit
```

### XOR (Bitwise XOR)
```mips
xor $rd, $rs, $rt    # $rd = $rs ^ $rt
```
- **Use Cases:**
  - Toggle bits
  - Basic encryption
  - Parity checking
- **Example:**
```mips
xor $t0, $t0, $t1    # Toggle bits where $t1 has 1s
xori $t0, $t0, -1    # Invert all bits
```

### NOR (Bitwise NOR)
```mips
nor $rd, $rs, $rt    # $rd = ~($rs | $rt)
```
- **Use Cases:**
  - Creating inverse masks
  - Complex logical operations
- **Example:**
```mips
nor $t0, $t1, $zero  # Bitwise NOT of $t1
```

## 3. Data Transfer Instructions

### LW (Load Word)
```mips
lw $rt, offset($rs)  # $rt = Memory[$rs + offset]
```
- **Use Cases:**
  - Loading variables from memory
  - Accessing array elements
  - Reading data structures
- **Example:**
```mips
lw $t0, 0($sp)       # Load word from stack
lw $t1, 4($s0)       # Load from array/structure
```

### SW (Store Word)
```mips
sw $rt, offset($rs)  # Memory[$rs + offset] = $rt
```
- **Use Cases:**
  - Saving variables to memory
  - Updating array elements
  - Writing to data structures
- **Example:**
```mips
sw $t0, 0($sp)       # Store word to stack
sw $t1, 8($s0)       # Store to array/structure
```

### LB/LBU (Load Byte/Load Byte Unsigned)
```mips
lb $rt, offset($rs)  # Load signed byte
lbu $rt, offset($rs) # Load unsigned byte
```
- **Use Cases:**
  - Character operations
  - Byte array access
  - Packed data structures
- **Example:**
```mips
lb $t0, 0($s0)       # Load signed byte
lbu $t1, 1($s0)      # Load unsigned byte
```

## 4. Branch Instructions

### BEQ (Branch if Equal)
```mips
beq $rs, $rt, label  # Branch to label if $rs == $rt
```
- **Use Cases:**
  - Equality comparisons
  - Loop termination
  - Conditional execution
- **Example:**
```mips
beq $t0, $zero, done # Branch if $t0 is zero
beq $t0, $t1, equal  # Branch if registers are equal
```

### BNE (Branch if Not Equal)
```mips
bne $rs, $rt, label  # Branch to label if $rs != $rt
```
- **Use Cases:**
  - Inequality testing
  - Loop continuation
  - Error checking
- **Example:**
```mips
bne $t0, $t1, loop   # Continue loop if not equal
bne $v0, $zero, error # Branch if error occurred
```

### BGTZ (Branch if Greater Than Zero)
```mips
bgtz $rs, label      # Branch if $rs > 0
```
- **Use Cases:**
  - Positive number testing
  - Counter validation
- **Example:**
```mips
bgtz $t0, positive   # Branch if $t0 is positive
```

### BLEZ (Branch if Less Than or Equal to Zero)
```mips
blez $rs, label      # Branch if $rs <= 0
```
- **Use Cases:**
  - Non-positive testing
  - Boundary conditions
- **Example:**
```mips
blez $t0, notpos     # Branch if $t0 <= 0
```

## 5. Jump Instructions

### J (Jump)
```mips
j label              # Jump to label
```
- **Use Cases:**
  - Unconditional branching
  - Loop implementation
  - Function calls
- **Example:**
```mips
j loop               # Jump to loop label
j exit               # Jump to program exit
```

### JAL (Jump and Link)
```mips
jal label           # Jump and store return address
```
- **Use Cases:**
  - Function calls
  - Subroutine linkage
- **Example:**
```mips
jal function        # Call function
```

### JR (Jump Register)
```mips
jr $rs              # Jump to address in $rs
```
- **Use Cases:**
  - Function returns
  - Computed jumps
  - Return from subroutine
- **Example:**
```mips
jr $ra              # Return from function
```

## 6. Comparison Instructions

### SLT (Set if Less Than)
```mips
slt $rd, $rs, $rt   # $rd = ($rs < $rt) ? 1 : 0
```
- **Use Cases:**
  - Comparing values
  - Implementing other comparisons
  - Sorting algorithms
- **Example:**
```mips
slt $t0, $t1, $t2   # Set $t0 to 1 if $t1 < $t2
```

### SLTI (Set if Less Than Immediate)
```mips
slti $rt, $rs, imm  # $rt = ($rs < imm) ? 1 : 0
```
- **Use Cases:**
  - Comparing with constants
  - Boundary checking
- **Example:**
```mips
slti $t0, $t1, 10   # Set $t0 to 1 if $t1 < 10
```

## 7. Shift Instructions

### SLL (Shift Left Logical)
```mips
sll $rd, $rt, shamt # $rd = $rt << shamt
```
- **Use Cases:**
  - Multiplication by powers of 2
  - Bit field manipulation
  - Hash functions
- **Example:**
```mips
sll $t0, $t1, 2     # Multiply $t1 by 4
```

### SRL (Shift Right Logical)
```mips
srl $rd, $rt, shamt # $rd = $rt >> shamt
```
- **Use Cases:**
  - Division by powers of 2
  - Bit extraction
  - Unsigned division
- **Example:**
```mips
srl $t0, $t1, 1     # Divide $t1 by 2 (unsigned)
```

## 8. Multiplication/Division Instructions

### MULT (Multiply)
```mips
mult $rs, $rt       # HI:LO = $rs * $rt
```
- **Use Cases:**
  - Integer multiplication
  - Complex calculations
- **Example:**
```mips
mult $t0, $t1       # Multiply $t0 and $t1
mflo $t2            # Get lower 32 bits of result
```

### DIV (Divide)
```mips
div $rs, $rt        # LO = $rs / $rt, HI = $rs % $rt
```
- **Use Cases:**
  - Integer division
  - Remainder calculations
- **Example:**
```mips
div $t0, $t1        # Divide $t0 by $t1
mflo $t2            # Get quotient
mfhi $t3            # Get remainder
```

## 9. Pseudo Instructions

### LI (Load Immediate)
```mips
li $rd, imm         # $rd = immediate
```
- **Use Cases:**
  - Loading constants
  - Initializing registers
  - Setting up syscall codes
- **Example:**
```mips
li $t0, 100         # Load 100 into $t0
li $v0, 1           # Setup print integer syscall
```

### LA (Load Address)
```mips
la $rd, label       # $rd = address of label
```
- **Use Cases:**
  - Getting addresses of variables
  - Setting up string pointers
  - Accessing data segment
- **Example:**
```mips
la $a0, message     # Load address of message
```

### MOVE (Move)
```mips
move $rd, $rs       # $rd = $rs
```
- **Use Cases:**
  - Register copying
  - Parameter passing
  - Saving values
- **Example:**
```mips
move $s0, $t0       # Copy $t0 to $s0
```

## Common Programming Patterns

### 1. Loop Implementation
```mips
    li $t0, 0           # Initialize counter
loop:
    beq $t0, 10, done   # Check exit condition
    # Loop body here
    addi $t0, $t0, 1    # Increment counter
    j loop              # Repeat
done:
```

### 2. If-Then-Else Structure
```mips
    bne $t0, $t1, else  # If condition
    # Then code here
    j endif
else:
    # Else code here
endif:
```

### 3. Function Call Pattern
```mips
main:
    # Setup
    jal function        # Call function
    # Handle return value

function:
    # Save registers
    sw $ra, 0($sp)      # Save return address
    # Function body
    lw $ra, 0($sp)      # Restore return address
    jr $ra              # Return
```

### 4. Array Access
```mips
    # Array access: array[i]
    sll $t0, $t1, 2     # Multiply index by 4
    add $t0, $t0, $s0   # Add base address
    lw $t2, 0($t0)      # Load array element
```

Remember:
1. Always check for corner cases
2. Maintain stack alignment
3. Follow calling conventions
4. Comment your code thoroughly
5. Consider performance implications

Would you like me to provide more specific examples or elaborate on any particular instruction or pattern?