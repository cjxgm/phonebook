// vim: noet ts=4 sw=4 sts=0 fenc=utf8
// Licensed under the MIT License. See COPYING for more details.
// (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

#pragma once
#include <unordered_map>
using namespace std;

/*
				nde's factory system

description:

	a factory is something that creates object by its registered
	string name. all the objects are the instances of the subclasses
	of Base.


usage:

	1.	create your classes. for example:

			struct Shape
			{
				virtual void who_am_i() = 0;
			};

			struct Circle: public Shape
			{
				void who_am_i() override { cout << "circle" << endl; }
			};

			struct Box: public Shape
			{
				void who_am_i() override { cout << "box" << endl; }
			};

		the base class is Shape, and 2 subclasses are Circle and Box.

	2.	create the factory.

			nde::Factory<Shape> shape_factory;

	3.	use the nde::Maker<T> proxy template class to create a new
		nde::Factory<Base>::Maker<T> object and add it to the factory.

			nde::Maker<Circle> maker_circle(shape_factory, "circle");
			nde::Maker<Box>    maker_box   (shape_factory, "box"   );

		so, we registered Circle with string name "circle" and registered
		Box with string name "box". the proxy can be deleted, but the
		maker created by it will remain persistent in memory.

	4.	now, we can create objects of Circle or Box by using the
		corresponding string name.

			shape_factory.make("circle")->who_am_i();
			shape_factory.make("box"   )->who_am_i();

		the output would be:

			circle
			box


caution:

	*	factory will never be correctly deleted, because they never
		need to.

	*	makers created by nde::Maker<T> will never be correctly deleted,
		because they never need to. the maker proxy itself can be safely
		deleted.
*/

namespace nde
{
	template <class Base>
	class Factory
	{
		struct MakerBase
		{
			virtual Base* make() = 0;
		};

		using Makers = unordered_map<string, MakerBase*>;
		Makers* makers = nullptr;

	public:
		template <class T>
		struct Maker : public MakerBase
		{
			Maker(Factory<Base>& fac, const string& name)
			{
				fac.add(name, this);
			}

			Base* make() override
			{
				// no need for deletion,
				// it's factory anyway.
				return new T{};
			}
		};


		Base* make(const string& name)
		{
			return (*makers)[name]->make();
		}

		void add(const string& name, MakerBase* maker)
		{
			if (!makers) makers = new Makers{};
			(*makers)[name] = maker;
		}
	};


	template <class T>
	struct Maker
	{
		template <class Base>
		Maker(Factory<Base>& fac, const string& name)
		{
			// no need for deletion,
			// it's a factory's maker anyway.
			new typename Factory<Base>::template Maker<T>{fac, name};
		}
	};
};

