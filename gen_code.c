// based on Float Calculator Example

#include <string.h>

#include "gen_code.h"
#include "id_attrs.h"
#include "id_use.h"
#include "literal_table.h"
#include "regname.h"
#include "utilities.h"

#define STACK_SPACE 4096

// Initialize the code generator
void gen_code_initialize()
{
	literal_table_initialize();
}

// Write all the instructions in code to bf in order
static void gen_code_output_seq(BOFFILE bf, code_seq code)
{
	while(!code_seq_is_empty(code))
	{
		bin_instr_t inst = code_seq_first(code)->instr;
		instruction_write_bin_instr(bf, inst);
		code = code_seq_rest(code);
	}
}

int max(int val1, int val2)
{
	return (val1 >= val2) ? val1 : val2;
}

// return a header appropriate for the given code
static BOFHeader gen_code_program_header(code_seq code)
{
	BOFHeader ret;
    strcpy(ret.magic, "BOF");
    ret.text_start_address = 0;
    ret.text_length = code_seq_size(code) * BYTES_PER_WORD;
    int dsa = max(ret.text_length, 1024);
    ret.data_start_address = dsa;
    ret.data_length = literal_table_size() * BYTES_PER_WORD;
    int sba = dsa + ret.data_start_address + ret.data_length + STACK_SPACE;
    ret.stack_bottom_addr = sba;
    return ret;
}

// writes literals to the data section of the bf
static void gen_code_output_literals(BOFFILE bf)
{
	literal_table_start_iteration();
	while(literal_table_iteration_has_next())
	{
		word_type val = literal_table_iteration_next();
		bof_write_word(bf, val);
	}
	literal_table_end_iteration();
}

static void gen_code_output_program(BOFFILE bf, code_seq main_seq)
{
	BOFHeader bfh = gen_code_program_header(main_seq);
	bof_write_header(bf, bfh);
	gen_code_output_seq(bf, main_seq);
	gen_code_output_literals(bf);
	bof_close(bf);
}

// Requires: bf if open for writing in binary
// Generate code for prog into bf
void gen_code_program(BOFFILE bf, block_t prog)
{
	literal_table_initialize();

	code_seq seq = gen_code_block(prog);

	gen_code_output_program(bf, seq);
}

// Requires: bf if open for writing in binary
// Generate code for the given AST
code_seq gen_code_block(block_t blk)
{
	code_seq = code_seq_empty();
	//constDecls
//	code_seq ret = gen_code_const_decls(blk.const_decls)
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

// dont need to implement
// (Stub for:) Generate code for the procedure declarations
code_seq gen_code_proc_decls(proc_decls_t pds)
{
	bail_with_error("TODO: no implementation of gen_code_proc_decls yet!");
	return code_seq_empty();
}

// don't need to implement
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
	// x := E
	// suppose offset for x is ofset (from id_use)
	// evaluate E onto the stack
	// get the frame pointer for x's location into a register, $t9
	// pop the stack into $at
	// SW $t9, $at, ofst
	bail_with_error("TODO: no implementation of gen_code_assign_stmt yet!");
	return code_seq_empty();
}

// don't need to implement
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
	code_seq ret;
	stmt_t *temp = stmts.stmts;

	while(temp != NULL)
	{
		ret = code_seq_concat(ret, gen_code_stmt(*temp));
		temp = temp->next;
	}

	return ret;
}

// Generate code for the if-statment given by stmt
code_seq gen_code_if_stmt(if_stmt_t stmt)
{
	
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
	// suppose offset for x is oft (from id_use)
	// RCH # puts char read into $v0
	// get the frame pointer for x's location into a register, $t9
	// SW $t9, $v0, ofst
	bail_with_error("TODO: no implementation of gen_code_read_stmt yet!");
	return code_seq_empty();
}

// Generate code for the write statment given by stmt.
code_seq gen_code_write_stmt(write_stmt_t stmt)
{	
	// look up N in global table,
	// receive N's offset (from $gp)
	// generate a load instruction into some registar (say, $v0)
	// LW $gp, $v0, offest
	// push $v0 onto the stack
	/*	
	unsigned int ofst = literal_table_lookup(stmt.expr.text, stmt.expr.value);
	code_lw(GP, AT, ofst);
	code_push_reg_on_stack(AT); 
	*/

	// evalue the expression (onto the stack)
	code_seq ret = gen_code_expr(stmt.expr);

	// pop the stack into $a0
	ret = code_seq_concat(ret, code_pop_stack_into_reg(A0));

	// PINT
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
	switch(cond.cond_kind)
	{
		case ck_odd:
			return gen_code_odd_condition(cond.data.odd_cond);
			break;
		case ck_rel:
			return gen_code_rel_op_condition(cond.data.rel_op_cond);
			break;
		default:
			bail_with_error("Bad cond passed to gen_code_condition");
			return code_seq_empty();
	}
}

// Generate code for cond, putting its truth value
// on top of the runtime stack
// and using V0 and AT as temporary registers
// Modifies SP, HI,LO when executed
code_seq gen_code_odd_condition(odd_condition_t cond)
{
	// Evaluate E1 to top of stack
	// pop top of stack (E1's value) into $v0
	// jump past 2 instrs
	// if GPR[$v0] % 2 == 0
	// HI = E1 % E2
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
	// code to evaluate E1
    code_seq ret = gen_code_expr(*(exp.expr1));
    // code to evaluate E2
    ret = code_seq_concat(ret, gen_code_expr(*(exp.expr2)));
    // code to push E2's value into $AT
    ret = code_seq_concat(ret, code_pop_stack_into_reg(T2));
    // code to push E1's value into $V0
    ret = code_seq_concat(ret, code_pop_stack_into_reg(T1));
    // OP $V0, $AT, $V0
    ret = code_seq_concat(ret, gen_code_arith_op(exp.arith_op));
    // code to push $V0 on the stack
    return code_seq_add_to_end(ret, code_push_reg_on_stack(V0));
}

// Generate code to apply arith_op to the
// 2nd from top and top of the stack,
// putting the result on top of the stack in their place,
// and using V0 and AT as temporary registers
// May also modify SP, HI,LO when executed
code_seq gen_code_arith_op(token_t arith_op)
{
//	code_seq ret;
	switch (arith_op.code) 
	{
	    case '+':
	    	// ADD $V0, $AT, $V0
			return code_add(V0, AT, V0);
			break;
	    case '-':
	    	// SUB $V0, $AT, $V0
			return code_sub(V0, AT, V0);
			break;
	    case '*':
	    	// MULT $V0, $AT
	    	// use MFHI and MFLO
//			ret = code_mul(V0, AT);
//			ret = code_seq_concat(ret, code_push_reg_on_stack(LO));
//			return code_seq_add_to_end(ret, code_push_reg_on_stack(HI));
			break;
	    case '/':
	    	// DIV $V0, $at
	    	// use MFHI and MFLO
//			ret = code_div(V0, AT);
//			ret = code_seq_concat(ret, code_push_reg_on_stack(LO));
//			return code_seq_add_to_end(ret, code_push_reg_on_stack(HI));
			break;
	    default:
			bail_with_error("gen_code_arith_op passed AST with bad op!");
			// The following should never execute
			return code_seq_empty();
    }

    // to get rid of warnings
    return code_seq_empty();
}

// Generate code to put the value of the given identifier
// on top of the stack
// Modifies T9, V0, and SP when executed
code_seq gen_code_ident(ident_t id)
{
	// no procedures, FP is the frame pointer for the AR

	// There are 2 instructions generated for each identifier declared
	// (one to allocate space and another to initialize that space)

	// allocate space
	code_seq ret = code_addi(SP, SP, -4);

	// initialize that space (below)
	// get offset of id from the literal table
	unsigned short ofst = id_use_get_attrs(id.idu)->offset_count;
	// LW $fp, $at, ofst
	ret = code_lw(FP, V0, ofst);
	// push reg onto stack
	ret = code_seq_add_to_end(ret, code_push_reg_on_stack(V0));

	return ret;
}

// Generate code to put the given number on top of the stack
code_seq gen_code_number(number_t num)
{
	unsigned int ofst = literal_table_lookup(num.text, num.value);
    return code_seq_concat(code_seq_singleton(code_lw(GP, V0, ofst)), code_push_reg_on_stack(V0));
}
