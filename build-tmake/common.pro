TARGET             = dime
TEMPLATE           = lib
INCLUDEPATH       += ../include;
unix:INCLUDEPATH  += $(ZLIBDIR)/include;
win32:INCLUDEPATH += $(ZLIBDIR);
win32:DEFINES     += DIME_NOT_DLL

HEADERS            = ../include/Basic.h \
                     ../include/Base.h \
                     ../include/Input.h \
                     ../include/Output.h \
                     ../include/Model.h \
                     ../include/RecordHolder.h \
	             ../include/Layer.h \
	             ../include/State.h \
                     ../include/util/Array.h \
                     ../include/util/Dict.h \
                     ../include/util/Linear.h \
                     ../include/util/MemHandler.h \
                     ../include/util/BSPTree.h \
                     ../include/util/Box.h \
                     ../include/records/Record.h \
                     ../include/records/StringRecord.h \ 
                     ../include/records/Int8Record.h \
                     ../include/records/Int16Record.h \
                     ../include/records/Int32Record.h \	  
                     ../include/records/DoubleRecord.h \
                     ../include/records/HexRecord.h \	  
                     ../include/records/FloatRecord.h \
                     ../include/sections/Section.h \
                     ../include/sections/UnknownSection.h \
                     ../include/sections/EntitiesSection.h \
                     ../include/sections/BlocksSection.h \
                     ../include/sections/TablesSection.h \
                     ../include/sections/HeaderSection.h \
                     ../include/sections/ClassesSection.h \
                     ../include/sections/ObjectsSection.h \
                     ../include/classes/Class.h \
                     ../include/classes/UnknownClass.h \
                     ../include/objects/Object.h \
                     ../include/objects/UnknownObject.h \
                     ../include/entities/Entity.h \
                     ../include/entities/UnknownEntity.h \
                     ../include/entities/FaceEntity.h \
                     ../include/entities/ExtrusionEntity.h \
	             ../include/entities/3DFace.h \
                     ../include/entities/Polyline.h \
                     ../include/entities/Vertex.h \
                     ../include/entities/Line.h \
                     ../include/entities/Point.h \
                     ../include/entities/Block.h \
                     ../include/entities/Insert.h \
                     ../include/entities/Solid.h \
                     ../include/entities/Trace.h \
                     ../include/entities/Circle.h \
	             ../include/entities/Ellipse.h \
                     ../include/entities/Arc.h \
                     ../include/entities/LWPolyline.h \
	             ../include/entities/Spline.h \
                     ../include/tables/Table.h \ 
                     ../include/tables/TableEntry.h \
                     ../include/tables/UnknownTable.h \
                     ../include/tables/UCSTable.h \
                     ../include/tables/LayerTable.h

SOURCES            = ../src/Base.cpp \
                     ../src/Input.cpp \
                     ../src/Output.cpp \
                     ../src/Model.cpp \
                     ../src/RecordHolder.cpp \
	             ../src/Layer.cpp \
                     ../src/State.cpp \
                     ../src/util/Array.cpp \
                     ../src/util/Dict.cpp \
                     ../src/util/Linear.cpp \
	             ../src/util/MemHandler.cpp \
                     ../src/util/BSPTree.cpp \
                     ../src/util/Box.cpp \
                     ../src/records/Record.cpp \
                     ../src/records/StringRecord.cpp \
                     ../src/records/Int8Record.cpp \
                     ../src/records/Int16Record.cpp \
                     ../src/records/Int32Record.cpp \
                     ../src/records/DoubleRecord.cpp \
                     ../src/records/HexRecord.cpp \
                     ../src/records/FloatRecord.cpp \
                     ../src/sections/Section.cpp \
                     ../src/sections/UnknownSection.cpp \
                     ../src/sections/EntitiesSection.cpp \
                     ../src/sections/BlocksSection.cpp \
                     ../src/sections/TablesSection.cpp \
                     ../src/sections/HeaderSection.cpp \
                     ../src/sections/ClassesSection.cpp \
                     ../src/sections/ObjectsSection.cpp \
                     ../src/classes/Class.cpp \
                     ../src/classes/UnknownClass.cpp \
                     ../src/objects/Object.cpp \
                     ../src/objects/UnknownObject.cpp \
                     ../src/entities/Entity.cpp \
                     ../src/entities/UnknownEntity.cpp \
                     ../src/entities/FaceEntity.cpp \
                     ../src/entities/ExtrusionEntity.cpp \
	             ../src/entities/3DFace.cpp \
                     ../src/entities/Polyline.cpp \
                     ../src/entities/Vertex.cpp \
                     ../src/entities/Line.cpp \
                     ../src/entities/Point.cpp \
                     ../src/entities/Block.cpp \
                     ../src/entities/Insert.cpp \
                     ../src/entities/Solid.cpp \
                     ../src/entities/Trace.cpp \
                     ../src/entities/Circle.cpp \
	             ../src/entities/Ellipse.cpp \
 	             ../src/entities/Spline.cpp \
                     ../src/entities/Arc.cpp \
                     ../src/entities/LWPolyline.cpp \
                     ../src/tables/Table.cpp \
                     ../src/tables/TableEntry.cpp \
                     ../src/tables/UnknownTable.cpp \
                     ../src/tables/UCSTable.cpp \
                     ../src/tables/LayerTable.cpp

