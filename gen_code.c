#include "gen_code.h"
#include "literal_table.h"
#include "regname.h"
#include "utilities.h"

#define BLOCKS_LINK_SIZE 4

// Initialize the code generator
void gen_code_initialize()
{
	// do nothing???
}

// Requires: bf if open for writing in binary
// Generate code for prog into bf
void gen_code_program(BOFFILE bf, block_t prog)
{
//	bail_with_error("TODO: no implementation of gen_code_program yet!");

	code_seq seq = gen_code_block(prog);

	// go through seq and write to the BOFFILE
}

// Requires: bf if open for writing in binary
// Generate code for the given AST
code_seq gen_code_block(block_t blk)
{
	code_seq ret = code_seq_singleton(code_allocate_stack_space(BLOCKS_LINK_SIZE));

	//constDecls
//	ret = code_seq_concat(ret, gen_code_const_decls(blk.const_decls));
	// varDecls
//	ret = code_seq_concat(ret, gen_code_var_decls(blk.var_decls));
	// procDecls
//	ret = code_seq_concat(ret, gen_code_proc_decls(blk.proc_decls));
	// stmt
	ret = code_seq_concat(ret, gen_code_stmt(blk.stmt));

	ret = code_seq_add_to_end(ret, code_exit());

	return ret;
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
	switch (stmt.stmt_kind) 
	{
	    case assign_stmt:
			return gen_code_assign_stmt(stmt.data.assign_stmt);
			break;
	    case call_stmt:
			return gen_code_call_stmt(stmt.data.call_stmt);
			break;
	    case begin_stmt:
			return gen_code_begin_stmt(stmt.data.begin_stmt);
			break;
	    case if_stmt:
			return gen_code_if_stmt(stmt.data.if_stmt);
			break;
	    case while_stmt:
			return gen_code_while_stmt(stmt.data.while_stmt);
			break;
		case read_stmt:
			return gen_code_read_stmt(stmt.data.read_stmt);
			break;
		case write_stmt:
			return gen_code_write_stmt(stmt.data.write_stmt);
			break;
		case skip_stmt:
			return gen_code_skip_stmt(stmt.data.skip_stmt);
	    default:
			bail_with_error("Bad stmt passed to gen_code_stmt!");
			// The following should never execute
			return code_seq_empty();
	}
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
/*	unsigned int ofst = literal_table_lookup(stmt.expr.text, stmt.expr.value);
	code_lw(GP, AT, ofst);
	code_push_reg_on_stack(AT); */
	
	// put the resul tof stmt_expr into $a0 to get ready for PCH
	// PCH:(syscal)
	
	// ret contains the code to compute the expression
	code_seq ret = gen_code_expr(stmt.expr);

	// code_pop_stack_into_reg() generates code to pop the top of the stack into register
	// Then code_seq_concat() prepares the results of the expr to be passed a an argument to a print function
	ret = code_seq_concat(ret, code_pop_stack_into_reg(A0));

	// code_seq_add_to_end() adds the print instruction to the end of the code
	ret = code_seq_add_to_end(ret, code_pint());

	return ret;
}

// Generate code for the skip statment, stmt
code_seq gen_code_skip_stmt(skip_stmt_t stmt)
{
	// SRL $at, $at, 0
	code_seq ret = code_srl(AT, AT, 0);

	return ret;
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
	switch (exp.expr_kind) 
	{
	    case expr_bin:
			return gen_code_binary_op_expr(exp.data.binary);
			break;
	    case expr_ident:
			return gen_code_ident(exp.data.ident);
			break;
	    case expr_number:
			return gen_code_number(exp.data.number);
			break;
	    default:
			bail_with_error("gen_code_expr passed bad expr!");
			// The following should never execute
			return code_seq_empty();
			break;
    }
}

// Generate code for the expression exp
// putting the result on top of the stack,
// and using V0 and AT as temporary registers
// May also modify SP, HI,LO when executed
code_seq gen_code_binary_op_expr(binary_op_expr_t exp)
{
	/* design:
        [code to push left exp's value on top of stack]
	[code to push right exp's value on top of stack]
	[instruction that implements the operation op]
    */

    code_seq ret = gen_code_expr(*(exp.expr1));
    ret = code_seq_concat(ret, gen_code_expr(*(exp.expr2)));
    return code_seq_add_to_end(ret, gen_code_arith_op(exp.arith_op));
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
