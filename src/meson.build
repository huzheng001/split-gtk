split_gtk_sources = [
  'main.cpp',
]

split_gtk_cpp_args = [
  '-DHAVE_CONFIG_H',
]

split_gtk_deps = [
  glib_dep,
  gtk_dep,
]

split_gtk_dep = declare_dependency(
  include_directories: rootdir,
  dependencies: split_gtk_deps,
)

split_gtk_exe = executable(
  package_name,
  split_gtk_sources,
  dependencies: split_gtk_dep,
  cpp_args: split_gtk_cpp_args,
  install: true,
  install_dir: bindir,
  install_rpath: pkglibdir,
)
