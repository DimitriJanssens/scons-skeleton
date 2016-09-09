env = Environment()

AddOption('--target', dest = 'target', nargs = 1, choices = ['host', 'axotec'], action = 'store', default = 'host', help = 'select build target')
AddOption('--debugbuild', dest = 'debugbuild', action = 'store_true', default = 'False', help = 'enable debugging symbols in build')
AddOption('--unittests', dest = 'unittests', action = 'store_true', default = 'False', help = 'enable unittest options and code coverage in build')

#set default env paths 
env['BUILD_ROOT'] = env.Dir('#do/%s' %(env.GetOption('target'))).abspath
env['BIN_DIR'] = env.Dir(env['BUILD_ROOT'] + '/bin').abspath
env['INC_DIR'] = env.Dir(env['BUILD_ROOT'] + '/include').abspath
env['LIB_DIR'] = env.Dir(env['BUILD_ROOT'] + '/lib').abspath

env['SYSTEMLIBS'] = [ ]

#set default flags
env['CCFLAGS'] = [ '-std=gnu99', '-Wall', '-Wextra', '-Werror', '-Wmissing-prototypes', '-Wmissing-declarations' ]
env['CPPPATH'] = [ '#/globalincludes', '#/framework/export', env['INC_DIR'] ]
env['CPPDEFINES'] = [ ]

#check options
if env.GetOption('target') == 'axotec':
  env['CC'] = '/usr/local/arm/4.9.2/usr/bin/arm-axotec-linux-gnueabi-gcc'
  env['CXX'] = '/usr/local/arm/4.9.2/usr/bin/arm-axotec-linux-gnueabi-g++'
  env['LD'] = '/usr/local/arm/4.9.2/usr/bin/arm-axotec-linux-gnueabi-ld'
  env['AR'] = '/usr/local/arm/4.9.2/usr/bin/arm-axotec-linux-gnueabi-ar'
  env['STRIP'] = '/usr/local/arm/4.9.2/usr/bin/arm-axotec-linux-gnueabi-strip'

if env.GetOption('debugbuild') == True:
  env['CCFLAGS'].append(['-g'])

if env.GetOption('unittests') == True:
  env['CCFLAGS'].append(['--coverage'])
  env['CPPDEFINES'].append(['UNITTESTS'])

# Optimise options
if env.GetOption('debugbuild') == True or env.GetOption('unittests') == True:
  env['CCFLAGS'].append(['-O0'])
else:
  env['CCFLAGS'].append(['-O3'])

#Add Custom Builders
from custom_builders import *
env.AddMethod(App, 'App')
env.AddMethod(Lib, 'Lib')

env.SConscript(dirs=['.'], name = 'SConscript', exports = 'env', variant_dir = env.Dir(env['BUILD_ROOT']).abspath, duplicate = 0)