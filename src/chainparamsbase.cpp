// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparamsbase.h"

#include "assert.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

//
// Main network
//

class CBaseMainParams : public CBaseChainParams {
public:
    CBaseMainParams() {
        networkID = CBaseChainParams::MAIN;
        nRPCPort = 8332;
    }
};
static CBaseMainParams mainParams;

//
// Testnet (v3)
//
class CBaseTestNetParams : public CBaseMainParams {
public:
    CBaseTestNetParams() {
        networkID = CBaseChainParams::TESTNET;
        nRPCPort = 18332;
        strDataDir = "testnet3";
    }
};
static CBaseTestNetParams testNetParams;

//
// Regression test
//
class CBaseRegTestParams : public CBaseTestNetParams {
public:
    CBaseRegTestParams() {
        networkID = CBaseChainParams::REGTEST;
        strDataDir = "regtest";
    }
};
static CBaseRegTestParams regTestParams;

//
// GCoin 5 min/tx
//
class CBaseGCoin30Params : public CBaseMainParams {
  public:
    CBaseGCoin30Params() {
      networkID = CBaseChainParams::GCOIN30;
      nRPCPort = 28332;
      strDataDir = "gcoin30";
    }
};
static CBaseGCoin30Params gCoin30Params;

//
// GCoin 2 min/tx
//
class CBaseGCoin12Params : public CBaseMainParams {
  public:
    CBaseGCoin12Params() {
      networkID = CBaseChainParams::GCOIN12;
      nRPCPort = 38332;
      strDataDir = "gcoin12";
    }
};
static CBaseGCoin12Params gCoin12Params;

//
// GCoin 10 sec/tx
//
class CBaseGCoin01Params : public CBaseMainParams {
  public:
    CBaseGCoin01Params() {
      networkID = CBaseChainParams::GCOIN01;
      nRPCPort = 48332;
      strDataDir = "gcoin01";
    }
};
static CBaseGCoin01Params gCoin01Params;

static CBaseChainParams *pCurrentBaseParams = 0;

const CBaseChainParams &BaseParams() {
    assert(pCurrentBaseParams);
    return *pCurrentBaseParams;
}

void SelectBaseParams(CBaseChainParams::Network network) {
    switch (network) {
        case CBaseChainParams::MAIN:
            pCurrentBaseParams = &mainParams;
            break;
        case CBaseChainParams::TESTNET:
            pCurrentBaseParams = &testNetParams;
            break;
        case CBaseChainParams::REGTEST:
            pCurrentBaseParams = &regTestParams;
            break;
        case CBaseChainParams::GCOIN30:
            pCurrentBaseParams = &gCoin30Params;
            break;
        case CBaseChainParams::GCOIN12:
            pCurrentBaseParams = &gCoin12Params;
            break;
        case CBaseChainParams::GCOIN01:
            pCurrentBaseParams = &gCoin01Params;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectBaseParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);
    bool fGCoin30 = GetBoolArg("-gcoin30", false);
    bool fGCoin12 = GetBoolArg("-gcoin12", false);
    bool fGCoin01 = GetBoolArg("-gcoin01", false);

    //TODO: use for loop to handle duplication problem
    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectBaseParams(CBaseChainParams::REGTEST);
    } else if (fTestNet) {
        SelectBaseParams(CBaseChainParams::TESTNET);
    } else if (fGCoin30) {
        SelectBaseParams(CBaseChainParams::GCOIN30);
    } else if (fGCoin12) {
        SelectBaseParams(CBaseChainParams::GCOIN12);
    } else if (fGCoin01) {
        SelectBaseParams(CBaseChainParams::GCOIN01);
    } else {
        SelectBaseParams(CBaseChainParams::MAIN);
    }
    return true;
}

bool AreBaseParamsConfigured() {
    return pCurrentBaseParams != NULL;
}
