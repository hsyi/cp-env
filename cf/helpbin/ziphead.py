#!/usr/bin/env python3

import re
import sys
import argparse
from logging import Logger, basicConfig, getLogger
from os import getenv, environ
from pathlib import Path
from typing import List


logger = getLogger(__name__)  # type: Logger

atcoder_include = re.compile('#include\s*["<](hesylib/[a-z_]*(|.hpp))[">]\s*')
code_start_statement = re.compile('//\s*CODE_START_HERE\s*')

include_guard = re.compile('#.*HESY_[A-Z_]*_HPP')

lib_path = Path.cwd()

defined = set()

if __name__ == "__main__":
    basicConfig(
        format="%(asctime)s [%(levelname)s] %(message)s",
        datefmt="%H:%M:%S",
        level=getenv('LOG_LEVEL', 'INFO'),
    )
    parser = argparse.ArgumentParser(description='Expander')
    parser.add_argument('source', help='Source File')
    opts = parser.parse_args()

    s = open(opts.source).read()

    result = ["#include<hesylib/head.hpp>"]
    flag = False
    for line in s.splitlines():
        if flag:
            result.append(line)
        m = code_start_statement.match(line)
        if m:
            flag = True

    output = '\n'.join(result) + '\n'
    with open('unzip.cpp', 'w') as f:
        f.write(output)
