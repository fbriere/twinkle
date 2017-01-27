# Generate a version string using git-describe, if applicable.
#
#  get_version_from_git(<variable>)
#
# Returns the version string if one was obtained; otherwise, <variable> will be
# untouched.

include (GetGitRevisionDescription)

function(get_version_from_git result_var)
	# Make sure we are running from a Git clone, not an unpacked tarball;
	# otherwise, Git will attempt to walk up the directory tree, and may
	# find an unrelated repo above.
	#
	# TODO: We should probably check the $GIT_DIR environment variable.
	if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")
		return()
	endif(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")

	# Fetch the version from git-describe.  --tags lifts the requirement
	# for annotated tags, and --match acts as a safety net to exclude any
	# non-version tag.  (The argument is a glob(7) pattern, not a regex.)
	git_describe(_version --tags --match "v[0-9]*")
	if(NOT "${_version}")
		return()
	endif(NOT "${_version}")

	# Strip the leading "v", if any.
	string(REGEX REPLACE "^v" "" _version "${_version}")

	# Check if we are on a dirty checkout, and append "-dirty" in that case.
	execute_process(COMMAND
		"${GIT_EXECUTABLE}"
		"update-index" "-q" "--refresh"
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
		OUTPUT_QUIET ERROR_QUIET)
	execute_process(COMMAND
		"${GIT_EXECUTABLE}"
		"diff-index" "--quiet" "HEAD" "--"
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
		RESULT_VARIABLE res
		OUTPUT_QUIET ERROR_QUIET)
	if(NOT res EQUAL 0)
		set(_version "${_version}-dirty")
	endif(NOT res EQUAL 0)

	set(${result_var} ${_version} PARENT_SCOPE)
endfunction()
