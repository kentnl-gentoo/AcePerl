/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RPCACE_H_RPCGEN
#define _RPCACE_H_RPCGEN

#include <rpc/rpc.h>


struct ace_data {
	char *question;
	struct {
		u_int reponse_len;
		char *reponse_val;
	} reponse;
	int clientId;
	int magic;
	int cardinal;
	int encore;
	int aceError;
	int kBytes;
};
typedef struct ace_data ace_data;
#ifdef __cplusplus 
extern "C" bool_t xdr_ace_data(XDR *, ace_data*);
#elif __STDC__ 
extern  bool_t xdr_ace_data(XDR *, ace_data*);
#else /* Old Style C */ 
bool_t xdr_ace_data();
#endif /* Old Style C */ 


struct ace_reponse {
	int ernumber;
	union {
		ace_data res_data;
	} ace_reponse_u;
};
typedef struct ace_reponse ace_reponse;
#ifdef __cplusplus 
extern "C" bool_t xdr_ace_reponse(XDR *, ace_reponse*);
#elif __STDC__ 
extern  bool_t xdr_ace_reponse(XDR *, ace_reponse*);
#else /* Old Style C */ 
bool_t xdr_ace_reponse();
#endif /* Old Style C */ 


#define RPC_ACE ((u_long)rpc_port)
#define RPC_ACE_VERS ((u_long)1)

#ifdef __cplusplus
#define ACE_SERVER ((u_long)1)
extern "C" ace_reponse * ace_server_1(ace_data *, CLIENT *);
extern "C" ace_reponse * ace_server_1_svc(ace_data *, struct svc_req *);

#elif __STDC__
#define ACE_SERVER ((u_long)1)
extern  ace_reponse * ace_server_1(ace_data *, CLIENT *);
extern  ace_reponse * ace_server_1_svc(ace_data *, struct svc_req *);

#else /* Old Style C */ 
#define ACE_SERVER ((u_long)1)
extern  ace_reponse * ace_server_1();
extern  ace_reponse * ace_server_1_svc();
#endif /* Old Style C */ 

#endif /* !_RPCACE_H_RPCGEN */
