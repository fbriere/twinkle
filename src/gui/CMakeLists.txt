project(twinkle-gui)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(twinkle_ui_SRC
	addresscardform.ui
	authenticationform.ui
	buddyform.ui
	deregisterform.ui
	diamondcardprofileform.ui
	dtmfform.ui
	getaddressform.ui
	getprofilenameform.ui
	historyform.ui
	inviteform.ui
	logviewform.ui
	messageform.ui
	mphoneform.ui
	numberconversionform.ui
	redirectform.ui
	selectnicform.ui
	selectprofileform.ui
	selectuserform.ui
	sendfileform.ui
	srvredirectform.ui
	syssettingsform.ui
	termcapform.ui
	transferform.ui
	userprofileform.ui
	wizardform.ui
)

set (twinkle_lang_SRC
	lang/twinkle_cs.ts
	lang/twinkle_de.ts
	lang/twinkle_fr.ts
	lang/twinkle_nl.ts
	lang/twinkle_ru.ts
	lang/twinkle_sk.ts
	lang/twinkle_sv.ts
)

# Versionless commands were introduced in Qt 5.15 to ease the Qt 6 transition.
# To ensure compatibility with older versions, we include our own copy of the
# functions that we need.
if (QT_VERSION VERSION_LESS 5.15.0)
	function(qt_wrap_ui outfiles)
		qt5_wrap_ui("${outfiles}" ${ARGN})
		set("${outfiles}" "${${outfiles}}" PARENT_SCOPE)
	endfunction()
	function(qt_add_resources outfiles)
		qt5_add_resources("${outfiles}" ${ARGN})
		set("${outfiles}" "${${outfiles}}" PARENT_SCOPE)
	endfunction()
	function(qt_add_translation _qm_files)
		qt5_add_translation("${_qm_files}" ${ARGN})
		set("${_qm_files}" "${${_qm_files}}" PARENT_SCOPE)
	endfunction()
endif ()

# Force the use of SIGNAL()/SLOT() for Qt 6 UIC
#   (see https://stackoverflow.com/a/77017651)
if (QT_VERSION_MAJOR EQUAL 6)
	list(APPEND twinkle_ui_SRC
		OPTIONS "--connections" "string")
endif ()
qt_wrap_ui(
	twinkle_UIS
	${twinkle_ui_SRC}
)

qt_add_resources(twinkle_QRC icons.qrc qml/qml.qrc)

qt_add_translation(twinkle_LANG
	${twinkle_lang_SRC}
)

set(qt_LIBS Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Quick)
if (QT_VERSION_MAJOR EQUAL 6)
	list(APPEND qt_LIBS Qt6::Core5Compat)
endif ()
if (WITH_DBUS)
	list(APPEND qt_LIBS Qt${QT_VERSION_MAJOR}::DBus)
endif (WITH_DBUS)

set(CMAKE_AUTOMOC ON)

set(TWINKLE_GUI-SRCS
	mphoneform.cpp
	inviteform.cpp
	getaddressform.cpp
	redirectform.cpp
	termcapform.cpp
	messageform.cpp
	srvredirectform.cpp
	userprofileform.cpp
	transferform.cpp
	syssettingsform.cpp
	historyform.cpp
	selectuserform.cpp
	selectprofileform.cpp
	buddyform.cpp
	diamondcardprofileform.cpp
	addresscardform.cpp
	authenticationform.cpp
	selectnicform.cpp
	sendfileform.cpp
	wizardform.cpp

	address_finder.cpp
	addresstablemodel.cpp
	buddylistview.cpp
	deregisterform.cpp
	dtmfform.cpp
	getprofilenameform.cpp
	gui.cpp
	logviewform.cpp
	main.cpp
	messageformview.cpp
	numberconversionform.cpp
	twinkleapplication.cpp
	yesnodialog.cpp
	osd.cpp
	incoming_call_popup.cpp
	idlesession_manager.cpp

	${twinkle_OBJS}
	${twinkle_UIS}
	${twinkle_QRC}
	${twinkle_LANG}
)
if (WITH_DBUS)
	list(APPEND TWINKLE_GUI-SRCS
		idlesession_inhibitor.cpp)
endif (WITH_DBUS)
if (WITH_AKONADI)
	list(APPEND qt_LIBS
		${AKONADI_PACKAGE_PREFIX}::AkonadiCore
		${AKONADI_PACKAGE_PREFIX}::AkonadiWidgets
		KF${QT_VERSION_MAJOR}::Contacts)
	list(APPEND TWINKLE_GUI-SRCS
		akonadiaddressbook.cpp
		kcontactstablemodel.cpp)
endif (WITH_AKONADI)

add_executable(twinkle ${TWINKLE_GUI-SRCS})
target_link_libraries(twinkle ${twinkle_LIBS} ${qt_LIBS})

install(TARGETS twinkle DESTINATION bin)
install(PROGRAMS twinkle-uri-handler DESTINATION bin)
install(FILES ${twinkle_LANG} DESTINATION share/twinkle/lang)
