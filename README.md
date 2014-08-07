Bitcoin Core OpenNet
====================

You need to compile first, please google how to do it.

Execution
---------

Only the 10 seconds version is available right now.

**Start up daemon**

```
$ bitcoind -gcoin01 -daemon
```

**Command line tool**

```
$ bitcoin-cli -gcoin01 getinfo
```

Configuration
-------------

* block chain generation time: 10 seconds
* subsidy halving interval: 946,000,000 blocks
* difficulty shift: 2,520 blocks
