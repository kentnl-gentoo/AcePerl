/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rpcace.h"

bool_t
xdr_ace_data (XDR *xdrs, ace_data *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_string (xdrs, &objp->question, ~0))
			 return FALSE;
		 if (!xdr_bytes (xdrs, (char **)&objp->reponse.reponse_val, (u_int *) &objp->reponse.reponse_len, ~0))
			 return FALSE;
		buf = XDR_INLINE(xdrs,6 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->clientId))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->magic))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->cardinal))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->encore))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->aceError))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->kBytes))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->clientId);
			IXDR_PUT_LONG(buf, objp->magic);
			IXDR_PUT_LONG(buf, objp->cardinal);
			IXDR_PUT_LONG(buf, objp->encore);
			IXDR_PUT_LONG(buf, objp->aceError);
			IXDR_PUT_LONG(buf, objp->kBytes);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_string (xdrs, &objp->question, ~0))
			 return FALSE;
		 if (!xdr_bytes (xdrs, (char **)&objp->reponse.reponse_val, (u_int *) &objp->reponse.reponse_len, ~0))
			 return FALSE;
		buf = XDR_INLINE(xdrs,6 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->clientId))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->magic))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->cardinal))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->encore))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->aceError))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->kBytes))
				 return FALSE;
		} else {
			objp->clientId = IXDR_GET_LONG(buf);
			objp->magic = IXDR_GET_LONG(buf);
			objp->cardinal = IXDR_GET_LONG(buf);
			objp->encore = IXDR_GET_LONG(buf);
			objp->aceError = IXDR_GET_LONG(buf);
			objp->kBytes = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_string (xdrs, &objp->question, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->reponse.reponse_val, (u_int *) &objp->reponse.reponse_len, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->clientId))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->magic))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->cardinal))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->encore))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->aceError))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->kBytes))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ace_reponse (XDR *xdrs, ace_reponse *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->ernumber))
		 return FALSE;
	switch (objp->ernumber) {
	case 0:
		 if (!xdr_ace_data (xdrs, &objp->ace_reponse_u.res_data))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}
