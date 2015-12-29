pkglangdir = $(pkgdatadir)/lang

pkglang_DATA = twinkle_nl.qm twinkle_de.qm
CLEANFILES = $(pkglang_DATA)

EXTRA_DIST = twinkle_nl.ts twinkle_de.ts

twinkle_nl.qm: $(top_builddir)/src/gui/twinkle $(top_builddir)/src/gui/twinkle.pro
	lrelease twinkle_nl.ts

twinkle_de.qm: $(top_builddir)/src/gui/twinkle $(top_builddir)/src/gui/twinkle.pro
	lrelease twinkle_de.ts
