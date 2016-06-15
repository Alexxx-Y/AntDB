
#ifndef MGR_CNDNNODE_H
#define MGR_CNDNNODE_H

#ifdef BUILD_BKI
#include "catalog/buildbki.h"
#else /* BUILD_BKI */
#include "catalog/genbki.h"
#endif /* BUILD_BKI */


#define NodeRelationId 4948

CATALOG(mgr_node,4948)
{
	NameData	nodename;		/* node name */
	Oid			nodehost;		/* node hostoid from host*/
	char		nodetype;		/* node type */
	int32		nodeport;		/* node port */
	bool		nodeinited;		/* is initialized */
	bool		nodeprimary;	/* is nodeis_primary, in pgxc_node*/
	Oid			nodemasternameoid;	/* 0 stands for the node is not slave*/
	bool		nodeincluster;		/*check the node in cluster*/
#ifdef CATALOG_VARLEN
	text		nodepath;		/* node data path */
#endif						/* CATALOG_VARLEN */
} FormData_mgr_node;

/* ----------------
 *		Form_mgr_node corresponds to a pointer to a tuple with
 *		the format of mgr_nodenode relation.
 * ----------------
 */
typedef FormData_mgr_node *Form_mgr_node;

/* ----------------
 *		compiler constants for mgr_node
 * ----------------
 */
#define Natts_mgr_node							9
#define Anum_mgr_node_nodename					1
#define Anum_mgr_node_nodehost					2
#define Anum_mgr_node_nodetype					3
#define Anum_mgr_node_nodeport					4
#define Anum_mgr_node_nodeinited				5
#define Anum_mgr_node_nodeprimary				6
#define Anum_mgr_node_nodemasternameOid			7
#define Anum_mgr_node_nodeincluster				8
#define Anum_mgr_node_nodepath					9

#define CNDN_TYPE_COORDINATOR_MASTER		'c'
#define CNDN_TYPE_COORDINATOR_SLAVE			's'
#define CNDN_TYPE_DATANODE_MASTER			'd'
#define CNDN_TYPE_DATANODE_SLAVE			'b'

#define MAX_WAL_SENDERS_NUM					5
#define WAL_KEEP_SEGMENTS_NUM				32
#define WAL_LEVEL_MODE						"hot_standby"

#endif /* MGR_CNDNNODE_H */