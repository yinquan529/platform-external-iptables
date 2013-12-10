#ifndef _XT_NFACCT_MATCH_H
#define _XT_NFACCT_MATCH_H

#include <linux/types.h>

#ifndef NFACCT_NAME_MAX
#define NFACCT_NAME_MAX 32
#endif

enum xt_quota_flags {
	XT_QUOTA_INVERT    = 1 << 0,
	XT_QUOTA_PACKET    = 1 << 1,
	XT_QUOTA_QUOTA     = 1 << 2,
};

struct nf_acct;
struct nf_acct_quota;

struct xt_nfacct_match_info {
	char		name[NFACCT_NAME_MAX];
	struct nf_acct	*nfacct;

	u_int8_t flags;
	aligned_u64 quota;

	/* Used by kernel */
	struct nf_acct_quota	*priv;
};

#endif /* _XT_NFACCT_MATCH_H */
