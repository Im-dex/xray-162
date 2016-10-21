////////////////////////////////////////////////////////////////////////////
//	Module 		: object_type_traits.h
//	Created 	: 21.01.2003
//  Modified 	: 12.07.2004
//	Author		: Dmitriy Iassenev
//	Description : Object type traits
////////////////////////////////////////////////////////////////////////////
#ifndef object_type_traits_h_included
#define object_type_traits_h_included
#pragma once

#include <type_traits>

	#define declare_has(a) \
		template <typename T>\
		struct has_##a {\
			template <typename P> static std::true_type  select(detail::other<typename P::a>*);\
			template <typename P> static std::false_type select(...);\
			static constexpr auto value = std::is_same<std::true_type, decltype(select<T>(nullptr))>::value;\
		};

	template <bool expression, typename T1, typename T2>
	struct _if {
		template <bool>
		struct selector {
			typedef T2 result;
		};

		template <>
		struct selector<true> {
			typedef T1 result;
		};

		typedef typename selector<expression>::result result;
	};

	namespace object_type_traits {
		namespace detail {
			template <typename T> struct other{};
		};

	    using std::is_pointer;
	    using std::is_reference;
	    using std::is_same;
        using std::remove_pointer;
        using std::remove_reference;
        using std::remove_const;
        using std::is_void;
        using std::is_const;

	    template <typename _T1, typename _T2>
	    struct is_base_and_derived
	    {
		    using T1 = std::remove_const_t<_T1>;
		    using T2 = std::remove_const_t<_T2>;

            static constexpr auto value = std::is_class<T1>::value && std::is_class<T2>::value && std::is_base_of<T1, T2>::value;
	    };

		template <template <typename _1> class T1, typename T2>
		struct is_base_and_derived_or_same_from_template {
			template <typename P>
			static std::true_type	select(T1<P>*);
			static std::false_type	select(...);

            static constexpr auto value = is_same<std::true_type, decltype(select(static_cast<T2*>(nullptr)))>::value;
		};

		declare_has(iterator);
		declare_has(const_iterator);
//		declare_has(reference);
//		declare_has(const_reference);
		declare_has(value_type);
		declare_has(size_type);
//		declare_has(value_compare);

		template <typename T>
		struct is_stl_container {
			enum { 
				value = 
					has_iterator<T>::value &&
					has_const_iterator<T>::value &&
//					has_reference<T>::value &&
//					has_const_reference<T>::value &&
					has_size_type<T>::value &&
					has_value_type<T>::value
			};
		};

//		template <typename _T>
//		struct is_tree_structure {
//			enum { 
//				value = 
//					has_value_compare<_T>::value
//			};
//		};
	};
#endif //	object_type_traits_h_included