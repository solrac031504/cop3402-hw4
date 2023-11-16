#include "gen_code.h"

// Initialize the code generator
void gen_code_initialize()
{
	bail_with_error("TODO: no implementation of gen_code_initialize yet!");
}

// Requires: bf if open for writing in binary
// Generate code for prog into bf
void gen_code_program(BOFFILE bf, block_t prog)
{
	bail_with_error("TODO: no implementation of gen_code_program yet!");
}

// Requires: bf if open for writing in binary
// Generate code for the given AST
code_seq gen_code_block(block_t blk)
{
	bail_with_error("TODO: no implementation of gen_code_block yet!");
	return code_seq_empty();
}

// Generate code for the const-decls, cds
// There are 3 instructions generated for each identifier declared
// (one to allocate space and two to initialize that space)
code_seq gen_code_const_decls(const_decls_t cds)
{
	bail_with_error("TODO: no implementation of gen_code_const_decls yet!");
	return code_seq_empty();
}

// Generate code for the const-decl, cd
code_seq gen_code_const_decl(const_decl_t cd)
{
	bail_with_error("TODO: no implementation of gen_code_const_decl yet!");
	return code_seq_empty();
}

// Generate code for the const-defs, cdfs
code_seq gen_code_const_defs(const_defs_t cdfs)
{
	bail_with_error("TODO: no implementation of gen_code_const_defs yet!");
	return code_seq_empty();
}

// Generate code for the const-def, cdf
code_seq gen_code_const_def(const_def_t cdf)
{
	bail_with_error("TODO: no implementation of gen_code_const_def yet!");
	return code_seq_empty();
}

// Generate code for the var_decls_t vds to out
// There are 2 instructions generated for each identifier declared
// (one to allocate space and another to initialize that space)
code_seq gen_code_var_decls(var_decls_t vds)
{
	bail_with_error("TODO: no implementation of gen_code_var_decls yet!");
	return code_seq_empty();
}

// Generate code for a single <var-decl>, vd,
// There are 2 instructions generated for each identifier declared
// (one to allocate space and another to initialize that space)
code_seq gen_code_var_decl(var_decl_t vd)
{
	bail_with_error("TODO: no implementation of gen_code_var_decl yet!");
	return code_seq_empty();
}

// Generate code for the identififers in idents
// in reverse order (so the first declared are allocated last).
// There are 2 instructions generated for each identifier declared
// (one to allocate space and another to initialize that space)
code_seq gen_code_idents(idents_t idents)
{
	bail_with_error("TODO: no implementation of gen_code_idents yet!");
	return code_seq_empty();
}

// (Stub for:) Generate code for the procedure declarations
code_seq gen_code_proc_decls(proc_decls_t pds)
{
	bail_with_error("TODO: no implementation of gen_code_proc_decls yet!");
	return code_seq_empty();
}

// (Stub for:) Generate code for a procedure declaration
code_seq gen_code_proc_decl(proc_decl_t pd)
{
	bail_with_error("TODO: no implementation of gen_code_proc_decl yet!");
	return code_seq_empty();
}

// Generate code for stmt
code_seq gen_code_stmt(stmt_t stmt)
{
	bail_with_error("TODO: no implementation of gen_code_stmt yet!");
	return code_seq_empty();
}

// Generate code for stmt
code_seq gen_code_assign_stmt(assign_stmt_t stmt)
{
	bail_with_error("TODO: no implementation of gen_code_assign_stmt yet!");
	return code_seq_empty();
}

// Generate code for stmt
code_seq gen_code_call_stmt(call_stmt_t stmt)
{
	bail_with_error("TODO: no implementation of gen_code_call_stmt yet!");
	return code_seq_empty();
}

// Generate code for stmt
code_seq gen_code_begin_stmt(begin_stmt_t stmt)
{
	bail_with_error("TODO: no implementation of gen_code_begin_stmt yet!");
	return code_seq_empty();
}

// Generate code for the list of statments given by stmts
code_seq gen_code_stmts(stmts_t stmts)
{
	bail_with_error("TODO: no implementation of gen_code_stmts yet!");
	return code_seq_empty();
}

// Generate code for the if-statment given by stmt
code_seq gen_code_if_stmt(if_stmt_t stmt)
{
	bail_with_error("TODO: no implementation of gen_code_if_stmt yet!");
	return code_seq_empty();
}

// Generate code for the if-statment given by stmt
code_seq gen_code_while_stmt(while_stmt_t stmt)
{
	bail_with_error("TODO: no implementation of gen_code_while_stmt yet!");
	return code_seq_empty();
}

// Generate code for the read statment given by stmt
code_seq gen_code_read_stmt(read_stmt_t stmt)
{
	bail_with_error("TODO: no implementation of gen_code_read_stmt yet!");
	return code_seq_empty();
}

// Generate code for the write statment given by stmt.
code_seq gen_code_write_stmt(write_stmt_t stmt)
{
	bail_with_error("TODO: no implementation of gen_code_write_stmt yet!");
	return code_seq_empty();
}

// Generate code for the skip statment, stmt
code_seq gen_code_skip_stmt(skip_stmt_t stmt)
{
	bail_with_error("TODO: no implementation of gen_code_skip_stmt yet!");
	return code_seq_empty();
}

// Requires: reg != T9
// Generate code for cond, putting its truth value
// on top of the runtime stack
// and using V0 and AT as temporary registers
// May modify HI,LO when executed
code_seq gen_code_condition(condition_t cond)
{
	bail_with_error("TODO: no implementation of gen_code_condition yet!");
	return code_seq_empty();
}

// Generate code for cond, putting its truth value
// on top of the runtime stack
// and using V0 and AT as temporary registers
// Modifies SP, HI,LO when executed
code_seq gen_code_odd_condition(odd_condition_t cond)
{
	bail_with_error("TODO: no implementation of gen_code_odd_condition yet!");
	return code_seq_empty();
}

// Generate code for cond, putting its truth value
// on top of the runtime stack
// and using V0 and AT as temporary registers
// May also modify SP, HI,LO when executed
code_seq gen_code_rel_op_condition(rel_op_condition_t cond)
{
	bail_with_error("TODO: no implementation of gen_code_rel_op_condition yet!");
	return code_seq_empty();
}

// Generate code for the rel_op
// applied to 2nd from top and top of the stack,
// putting the result on top of the stack in their place,
// and using V0 and AT as temporary registers
// May also modify SP, HI,LO when executed
code_seq gen_code_rel_op(token_t rel_op)
{
	bail_with_error("TODO: no implementation of gen_code_rel_op yet!");
	return code_seq_empty();
}

// Generate code for the expression exp
// putting the result on top of the stack,
// and using V0 and AT as temporary registers
// May also modify SP, HI,LO when executed
code_seq gen_code_expr(expr_t exp)
{
	bail_with_error("TODO: no implementation of gen_code_expr yet!");
	return code_seq_empty();
}

// Generate code for the expression exp
// putting the result on top of the stack,
// and using V0 and AT as temporary registers
// May also modify SP, HI,LO when executed
code_seq gen_code_binary_op_expr(binary_op_expr_t exp)
{
	bail_with_error("TODO: no implementation of gen_code_binary_op_expr yet!");
	return code_seq_empty();
}

// Generate code to apply arith_op to the
// 2nd from top and top of the stack,
// putting the result on top of the stack in their place,
// and using V0 and AT as temporary registers
// May also modify SP, HI,LO when executed
code_seq gen_code_arith_op(token_t arith_op)
{
	bail_with_error("TODO: no implementation of gen_code_arith_op yet!");
	return code_seq_empty();
}

// Generate code to put the value of the given identifier
// on top of the stack
// Modifies T9, V0, and SP when executed
code_seq gen_code_ident(ident_t id)
{
	bail_with_error("TODO: no implementation of gen_code_ident yet!");
	return code_seq_empty();
}

// Generate code to put the given number on top of the stack
code_seq gen_code_number(number_t num)
{
	bail_with_error("TODO: no implementation of gen_code_number yet!");
	return code_seq_empty();
}
