// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.

#define ORDER_PP_DEF_8seq(...) 8EVAL_SEQ,(,__VA_ARGS__,0seq),

#ifdef ORDER_PP_DEBUG
#define ORDER_PP_8EVAL_SEQ(P,e,ts,G,...) ORDER_PP_ASSERT_SYNTAX(ORDER_PP_DEF_FIRST P##ts())(,P##e,ORDER_PP_DEF_FIRST P##ts,8EVAL_SEQ_B,,P##e,ORDER_PP_TUPLE_REST P##ts,P##__VA_ARGS__)
#define ORDER_PP_8EVAL_SEQ_B(P,v,s,e,t,...) ORDER_PP_ASSERT_SYNTAX(ORDER_PP_DEF_##t())(,P##e,ORDER_PP_DEF_##t,8EVAL_SEQ_B,P##s(P##v),P##e,P##__VA_ARGS__)
#else
#define ORDER_PP_8EVAL_SEQ(P,e,ts,G,...) (,P##e,ORDER_PP_DEF_FIRST P##ts,8EVAL_SEQ_B,,P##e,ORDER_PP_TUPLE_REST P##ts,P##__VA_ARGS__)
#define ORDER_PP_8EVAL_SEQ_B(P,v,s,e,t,...) (,P##e,ORDER_PP_DEF_##t,8EVAL_SEQ_B,P##s(P##v),P##e,P##__VA_ARGS__)
#endif
#define ORDER_PP_DEF_0seq 0EVAL_SEQ,
#define ORDER_PP_0EVAL_SEQ(P,e1,G,eval_seq_b,s,e2,K,...) ORDER_PP_##K(,P##s,P##__VA_ARGS__)
