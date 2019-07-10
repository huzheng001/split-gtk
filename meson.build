project(
  'split-gtk', 'cpp',
  version: '1.0.0',
  license: 'GPL3'
)

i18n = import('i18n')
pkg = import('pkgconfig')

# Versioning
version = meson.project_version()
version_arr = version.split('.')
version_major = version_arr[0]
version_minor = version_arr[1]
version_micro = version_arr[2]

api_version = '1.0'

package_name = meson.project_name()
package_string = '@0@-@1@'.format(package_name, api_version)

# Paths
rootdir = include_directories('.')

prefix = get_option('prefix')

bindir = join_paths(prefix, get_option('bindir'))
includedir = join_paths(prefix, get_option('includedir'))
libdir = join_paths(prefix, get_option('libdir'))
datadir = join_paths(prefix, get_option('datadir'))
pkgconfigdir = join_paths(libdir, 'pkgconfig')
pkglibdir = join_paths(libdir, package_name)

localdir = join_paths(datadir, 'local')

# Dependencies
glib_req = '>= 2.44.0'
gtk_req = '>= 3.22.0'

glib_dep = dependency('glib-2.0', version: glib_req)
gtk_dep = dependency('gtk+-3.0', version: gtk_req)

config_h = configuration_data()
config_h.set_quoted('PACKAGE_NAME', package_name)
config_h.set_quoted('PACKAGE_STRING', package_string)
config_h.set_quoted('PACKAGE_VERSION', version)
config_h.set_quoted('GETTEXT_PACKAGE', package_name)
config_h.set_quoted('SPLIT_GTK_LOCALEDIR', localdir)
config_h.set_quoted('LIBDIR', libdir)
config_h.set_quoted('DATADIR', datadir)
config_h.set_quoted('VERSION', version)

config_h.set('SPLIT_GTK_MAJOR_VERSION', version_major)
config_h.set('SPLIT_GTK_MINOR_VERSION', version_minor)
config_h.set('SPLIT_GTK_MICRO_VERSION', version_micro)

configure_file(
  output: 'config.h',
  configuration: config_h
)

subdir('po')
subdir('src')

