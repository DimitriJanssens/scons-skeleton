env = Environment()

#set default build to printing aliases
env.Default(None)

AddOption('--aliases', dest = 'aliases', action = 'store_true', default = 'False', help = 'display all available aliases')
AddOption('--target', dest = 'target', nargs = 1, choices = ['host', 'axotec'], action = 'store', default = 'host', help = 'select build target')
AddOption('--debugbuild', dest = 'debugbuild', action = 'store_true', default = 'False', help = 'enable debugging symbols in build')
AddOption('--unittests', dest = 'unittests', action = 'store_true', default = 'False', help = 'enable unittest options and code coverage in build')

#set default env paths
env['BUILD_ROOT'] = env.Dir('#do/%s' %(env.GetOption('target')))
env['BIN_DIR'] = env['BUILD_ROOT'].Dir('bin')
env['ETC_DIR'] = env['BUILD_ROOT'].Dir('etc')
env['INC_DIR'] = env['BUILD_ROOT'].Dir('include')
env['LIB_DIR'] = env['BUILD_ROOT'].Dir('lib')
env['THIRD_PARTY_DIR'] = env['BUILD_ROOT'].Dir('third-party')
env['THIRD_PARTY_BIN_DIR'] = env['THIRD_PARTY_DIR'].Dir('bin')
env['THIRD_PARTY_INC_DIR'] = env['THIRD_PARTY_DIR'].Dir('include')
env['THIRD_PARTY_LIB_DIR'] = env['THIRD_PARTY_DIR'].Dir('lib')
env['TOOLCHAINS_DIR'] = env.Dir('#do/toolchains')

#set default flags
env['CCFLAGS'] = [
  '-std=gnu99',
  '-Wall',
  '-Wbad-function-cast',
  '-Wcast-align',
  '-Wcast-qual',
#  '-Wconversion', makes you thing twice about integer types and signedness: this would be very nice ... but causes a lot of refactoring due to implicit int casting with arithmetics
  '-Werror',
  '-Wextra',
  '-Wformat=2',
  '-Wmissing-declarations',
  '-Wmissing-prototypes',
  '-Wnested-externs',
  '-Wno-int-to-pointer-cast',
  '-Wno-pointer-to-int-cast',
  '-Wpointer-arith',
  '-Wshadow',
  '-Wstrict-prototypes',
  '-Wwrite-strings',
]
env['CPPPATH'] = [ env.Dir('energyville/globalincludes').srcnode(), env.Dir('framework/globalincludes').srcnode(), env['INC_DIR'], env['THIRD_PARTY_INC_DIR'] ]
env['CPPDEFINES'] = [ ]

#check options

if env.GetOption('debugbuild') == True:
  env['CCFLAGS'].append('-g')

if env.GetOption('unittests') == True:
  env['CCFLAGS'].append('--coverage')
  env['CPPDEFINES'].append('UNITTESTS')

# Optimise options
if env.GetOption('debugbuild') == True or env.GetOption('unittests') == True:
  env['CCFLAGS'].append('-O0')
else:
  env['CCFLAGS'].append('-O3')

#Add Custom Builders
from custom_builders import *
env.AddMethod(App, 'App')
env.AddMethod(Lib, 'Lib')

env.SConscript(dirs=['.'], name = 'SConscript', exports = 'env', variant_dir = env['BUILD_ROOT'], duplicate = 0)

#Keep this after the sconscript function! All scripts must be read in order to fetch all aliases
if env.GetOption('aliases') == True:
  #print available aliases
  from SCons.Node.Alias import default_ans
  aliases = default_ans.keys()
  aliases.sort()
  print 'Recognised targets:'
  for alias in aliases:
    print '    %s' % alias
