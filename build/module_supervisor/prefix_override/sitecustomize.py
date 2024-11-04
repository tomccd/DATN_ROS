import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/tomccd/Documents/Code/Python/DATN/install/module_supervisor'
