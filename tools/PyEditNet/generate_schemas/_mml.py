# ./_mml.py
# -*- coding: utf-8 -*-
# PyXB bindings for NM:b5ff3bc3190e213a74fd561e7efcdf1de931b56a
# Generated 2013-05-15 10:45:58.959028 by PyXB version 1.2.2
# Namespace http://morphml.org/morphml/schema [xmlns:mml]

import pyxb
import pyxb.binding
import pyxb.binding.saxer
import StringIO
import pyxb.utils.utility
import pyxb.utils.domutils
import sys

# Unique identifier for bindings created at the same time
_GenerationUID = pyxb.utils.utility.UniqueIdentifier('urn:uuid:3e63be78-bd44-11e2-929c-90e6ba985e9d')

# Version of PyXB used to generate the bindings
_PyXBVersion = '1.2.2'
# Generated bindings are not compatible across PyXB versions
if pyxb.__version__ != _PyXBVersion:
    raise pyxb.PyXBVersionError(_PyXBVersion)

# Import bindings for namespaces imported into schema
import _nsgroup as _ImportedBinding__nsgroup

# NOTE: All namespace declarations are reserved within the binding
Namespace = pyxb.namespace.NamespaceForURI(u'http://morphml.org/morphml/schema', create_if_missing=True)
Namespace.configureCategories(['typeBinding', 'elementBinding'])

def CreateFromDocument (xml_text, default_namespace=None, location_base=None):
    """Parse the given XML and use the document element to create a
    Python instance.
    
    @kw default_namespace The L{pyxb.Namespace} instance to use as the
    default namespace where there is no default namespace in scope.
    If unspecified or C{None}, the namespace of the module containing
    this function will be used.

    @keyword location_base: An object to be recorded as the base of all
    L{pyxb.utils.utility.Location} instances associated with events and
    objects handled by the parser.  You might pass the URI from which
    the document was obtained.
    """

    if pyxb.XMLStyle_saxer != pyxb._XMLStyle:
        dom = pyxb.utils.domutils.StringToDOM(xml_text)
        return CreateFromDOM(dom.documentElement)
    if default_namespace is None:
        default_namespace = Namespace.fallbackNamespace()
    saxer = pyxb.binding.saxer.make_parser(fallback_namespace=default_namespace, location_base=location_base)
    handler = saxer.getContentHandler()
    saxer.parse(StringIO.StringIO(xml_text))
    instance = handler.rootObject()
    return instance

def CreateFromDOM (node, default_namespace=None):
    """Create a Python instance from the given DOM node.
    The node tag must correspond to an element declaration in this module.

    @deprecated: Forcing use of DOM interface is unnecessary; use L{CreateFromDocument}."""
    if default_namespace is None:
        default_namespace = Namespace.fallbackNamespace()
    return pyxb.binding.basis.element.AnyCreateFromDOM(node, default_namespace)

from _nsgroup import morphml # {http://morphml.org/morphml/schema}morphml
from _nsgroup import CTD_ANON_3 as CTD_ANON # None
from _nsgroup import CTD_ANON_4 as CTD_ANON_ # None
from _nsgroup import CTD_ANON_5 as CTD_ANON_2 # None
from _nsgroup import Cells # {http://morphml.org/morphml/schema}Cells
from _nsgroup import Cell # {http://morphml.org/morphml/schema}Cell
from _nsgroup import CTD_ANON_6 as CTD_ANON_3 # None
from _nsgroup import CTD_ANON_7 as CTD_ANON_4 # None
from _nsgroup import CTD_ANON_8 as CTD_ANON_5 # None
from _nsgroup import CTD_ANON_9 as CTD_ANON_6 # None
from _nsgroup import CableGroup # {http://morphml.org/morphml/schema}CableGroup
from _nsgroup import CTD_ANON_10 as CTD_ANON_7 # None
from _nsgroup import Metric # {http://morphml.org/morphml/schema}Metric
from _nsgroup import InhomogeneousParam # {http://morphml.org/morphml/schema}InhomogeneousParam
from _nsgroup import CTD_ANON_11 as CTD_ANON_8 # None
from _nsgroup import CTD_ANON_12 as CTD_ANON_9 # None
from _nsgroup import SpineShape # {http://morphml.org/morphml/schema}SpineShape
from _nsgroup import Feature # {http://morphml.org/morphml/schema}Feature
from _nsgroup import Morphology # {http://morphml.org/morphml/schema}Morphology
from _nsgroup import Segment # {http://morphml.org/morphml/schema}Segment
from _nsgroup import Cable # {http://morphml.org/morphml/schema}Cable
from _nsgroup import Spine # {http://morphml.org/morphml/schema}Spine
from _nsgroup import FreePoints # {http://morphml.org/morphml/schema}FreePoints
from _nsgroup import Path # {http://morphml.org/morphml/schema}Path
