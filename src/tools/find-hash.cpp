#include <iostream>
#include <vector>
#include "core.h"

using namespace std;

int main(int argc, char *argv[]){
  CBlock genesis;
  uint256 bnProofOfWorkLimit = ~uint256(0) >> 20;
  const char* pszTimestamp = "OpenNet GCoin Project 2014/8";
  CMutableTransaction txNew;
  txNew.vin.resize(1);
  txNew.vout.resize(1);
  txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
  txNew.vout[0].nValue = 50 * COIN;
  txNew.vout[0].scriptPubKey = CScript() << ParseHex("04a3a8584b519bb42f63defcdd1bec62e685d8204ebe83a02f80cae170c207934591a1e739bad2f5ed632844c636504d8587ecabaf0b3168afb4f613895fd1105a") << OP_CHECKSIG;
  genesis.vtx.push_back(txNew);
  genesis.hashPrevBlock = 0;
  genesis.hashMerkleRoot = genesis.BuildMerkleTree();
  genesis.nVersion = 1;
  genesis.nTime    = 1407252803;
  genesis.nBits    = bnProofOfWorkLimit.GetCompact();
  genesis.nNonce   = 2084524493;
  uint256 hashGenesisBlock = genesis.GetHash();
  printf("%08x\n",hashGenesisBlock.GetCompact());
  return 0;
}
