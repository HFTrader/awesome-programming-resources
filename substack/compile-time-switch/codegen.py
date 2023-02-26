#!/usr/bin/env python3
import sys, os
from mako.template import Template

if len(sys.argv)<2: 
    print( "Usage: codegen.py <template> [args...]")
    sys.exit(0)

template = sys.argv[1]
argv = sys.argv[2:]
contents = open( template ).read()
print(Template(contents).render(argv=argv,template=template))
