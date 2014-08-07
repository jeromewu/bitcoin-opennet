#!/usr/bin/env python2.7
#
# copied from https://gitorious.org/bitcoin/luke-jr-bitcoin/commit/9126e08739f5115c3032997cabd23f27037131ef
#

import re
import sys
from subprocess import check_output

def main():
  lines = sys.stdin.readlines()

  ips = []
  pattern = re.compile(r"^(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}):28333")
  for line in lines:
    m = pattern.match(line)
    if m is None:
      continue
    ip = 0
    for i in range(0, 4):
      ip = ip + (int(m.group(i+1)) << (8*(i)))
    if ip == 0:
      continue
    ips.append(ip)

  for row in range(0, len(ips), 8):
    print "    " + ", ".join([ "0x%08x"%i for i in ips[row:row+8] ]) + ","

if __name__ == '__main__':
  main()
