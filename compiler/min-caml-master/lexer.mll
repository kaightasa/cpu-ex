{
(* lexer�����Ѥ����ѿ����ؿ������ʤɤ���� *)
open Parser
open Type
}

(* ����ɽ����ά�� *)
let space = [' ' '\t']
let digit = ['0'-'9']
let lower = ['a'-'z']
let upper = ['A'-'Z']
(* ����1-��������\r\n�Ͼ��space�ˤ��� *)
let enter = ['\n' '\r']

rule token = parse
| space+
    { token lexbuf }
| enter
    { Lexing.new_line lexbuf;
      token lexbuf}
| "(*"
    { comment lexbuf; (* �ͥ��Ȥ��������ȤΤ���Υȥ�å� *)
      token lexbuf }
| '('
    { LPAREN }
| ')'
    { RPAREN }
| "true"
    { BOOL(true) }
| "false"
    { BOOL(false) }
| "not"
    { NOT }
| digit+ (* �����������Ϥ���롼�� (caml2html: lexer_int) *)
    { INT(int_of_string (Lexing.lexeme lexbuf)) }
| digit+ ('.' digit*)? (['e' 'E'] ['+' '-']? digit+)?
    { FLOAT(float_of_string (Lexing.lexeme lexbuf)) }
| '-' (* -.����󤷤ˤ��ʤ��Ƥ��ɤ�? ��Ĺ����? *)
    { MINUS }
| '+' (* +.����󤷤ˤ��ʤ��Ƥ��ɤ�? ��Ĺ����? *)
    { PLUS }
| '*' (* *.����󤷤ˤ��ʤ��Ƥ��ɤ�? ��Ĺ����? *)
    { AST }
| '/' (* /.����󤷤ˤ��ʤ��Ƥ��ɤ�? ��Ĺ����? *)
    { SLASH }
(*
| "/"^space*^"2"
    { RSHIFT2 }
*)
| "-."
    { MINUS_DOT }
| "+."
    { PLUS_DOT }
| "*."
    { AST_DOT }
| "/."
    { SLASH_DOT }
| '='
    { EQUAL }
| "<>"
    { LESS_GREATER }
| "<="
    { LESS_EQUAL }
| ">="
    { GREATER_EQUAL }
| '<'
    { LESS }
| '>'
    { GREATER }
| "if"
    { IF }
| "then"
    { THEN }
| "else"
    { ELSE }
| "let"
    { LET }
| "in"
    { IN }
| "rec"
    { REC }
| ','
    { COMMA }
| '_'
    { IDENT(Id.gentmp Type.Unit) }
| "Array.create" | "Array.make" (* [XX] ad hoc *)
    { ARRAY_CREATE }
| '.'
    { DOT }
| "<-"
    { LESS_MINUS }
| ';'
    { SEMICOLON }
| eof
    { EOF }
| lower (digit|lower|upper|'_')* (* ¾�Ρ�ͽ���פ���Ǥʤ��Ȥ����ʤ� *)
    { IDENT(Lexing.lexeme lexbuf) }
| _
    { failwith
        ( let err_start = lexbuf.lex_curr_p.pos_cnum - lexbuf.lex_curr_p.pos_bol in (* pos_cnum�Ϲ�Ƭ�Υ����ɤ���Ƭ�����ʸ����, pos_bol�ϸ��߰��֤Υ����ɤ���Ƭ�����ʸ���� *)
          Printf.sprintf "unknown token %s near line %d, characters %d-%d"
           (Lexing.lexeme lexbuf)
           (lexbuf.lex_curr_p.pos_lnum)
           err_start
           (err_start + 1))
(*
           (Lexing.lexeme_start lexbuf)
           (Lexing.lexeme_end lexbuf))
*)
           }
and comment = parse
| "*)"
    { () }
| "(*"
    { comment lexbuf;
      comment lexbuf }
| eof
    { Format.eprintf "warning: unterminated comment@." }
| _
    { comment lexbuf }
