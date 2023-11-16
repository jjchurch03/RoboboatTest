# generated from rosidl_generator_py/resource/_idl.py.em
# with input from detector:msg/MyCustomMsgDetector.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'object_scores'
# Member 'object_bounding_boxes'
# Member 'object_positions'
# Member 'object_orientations'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MyCustomMsgDetector(type):
    """Metaclass of message 'MyCustomMsgDetector'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('detector')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'detector.msg.MyCustomMsgDetector')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__my_custom_msg_detector
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__my_custom_msg_detector
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__my_custom_msg_detector
            cls._TYPE_SUPPORT = module.type_support_msg__msg__my_custom_msg_detector
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__my_custom_msg_detector

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MyCustomMsgDetector(metaclass=Metaclass_MyCustomMsgDetector):
    """Message class 'MyCustomMsgDetector'."""

    __slots__ = [
        '_frame_id',
        '_object_classes',
        '_object_scores',
        '_object_bounding_boxes',
        '_object_positions',
        '_object_orientations',
    ]

    _fields_and_field_types = {
        'frame_id': 'string',
        'object_classes': 'sequence<string>',
        'object_scores': 'sequence<float>',
        'object_bounding_boxes': 'sequence<float>',
        'object_positions': 'sequence<float>',
        'object_orientations': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.frame_id = kwargs.get('frame_id', str())
        self.object_classes = kwargs.get('object_classes', [])
        self.object_scores = array.array('f', kwargs.get('object_scores', []))
        self.object_bounding_boxes = array.array('f', kwargs.get('object_bounding_boxes', []))
        self.object_positions = array.array('f', kwargs.get('object_positions', []))
        self.object_orientations = array.array('f', kwargs.get('object_orientations', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.frame_id != other.frame_id:
            return False
        if self.object_classes != other.object_classes:
            return False
        if self.object_scores != other.object_scores:
            return False
        if self.object_bounding_boxes != other.object_bounding_boxes:
            return False
        if self.object_positions != other.object_positions:
            return False
        if self.object_orientations != other.object_orientations:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def frame_id(self):
        """Message field 'frame_id'."""
        return self._frame_id

    @frame_id.setter
    def frame_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'frame_id' field must be of type 'str'"
        self._frame_id = value

    @property
    def object_classes(self):
        """Message field 'object_classes'."""
        return self._object_classes

    @object_classes.setter
    def object_classes(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'object_classes' field must be a set or sequence and each value of type 'str'"
        self._object_classes = value

    @property
    def object_scores(self):
        """Message field 'object_scores'."""
        return self._object_scores

    @object_scores.setter
    def object_scores(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'object_scores' array.array() must have the type code of 'f'"
            self._object_scores = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'object_scores' field must be a set or sequence and each value of type 'float'"
        self._object_scores = array.array('f', value)

    @property
    def object_bounding_boxes(self):
        """Message field 'object_bounding_boxes'."""
        return self._object_bounding_boxes

    @object_bounding_boxes.setter
    def object_bounding_boxes(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'object_bounding_boxes' array.array() must have the type code of 'f'"
            self._object_bounding_boxes = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'object_bounding_boxes' field must be a set or sequence and each value of type 'float'"
        self._object_bounding_boxes = array.array('f', value)

    @property
    def object_positions(self):
        """Message field 'object_positions'."""
        return self._object_positions

    @object_positions.setter
    def object_positions(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'object_positions' array.array() must have the type code of 'f'"
            self._object_positions = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'object_positions' field must be a set or sequence and each value of type 'float'"
        self._object_positions = array.array('f', value)

    @property
    def object_orientations(self):
        """Message field 'object_orientations'."""
        return self._object_orientations

    @object_orientations.setter
    def object_orientations(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'object_orientations' array.array() must have the type code of 'f'"
            self._object_orientations = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'object_orientations' field must be a set or sequence and each value of type 'float'"
        self._object_orientations = array.array('f', value)
