#ifndef BLOCKCHAIN_OBJECTS_H
#define BLOCKCHAIN_OBJECTS_H

#include "cryptonote_core/blockchain.h"
#include "cryptonote_core/tx_pool.h"
#include "cryptonote_core/masternode_list.h"
#include "cryptonote_core/masternode_voting.h"

// NOTE(quenero): This is done this way because of the circular constructors.
struct blockchain_objects_t
{
  cryptonote::Blockchain m_blockchain;
  cryptonote::tx_memory_pool m_mempool;
  masternodes::masternode_list m_masternode_list;
  blockchain_objects_t() :
    m_blockchain(m_mempool, m_masternode_list),
    m_masternode_list(m_blockchain),
    m_mempool(m_blockchain) { }
};

#endif // BLOCKCHAIN_OBJECTS_H
