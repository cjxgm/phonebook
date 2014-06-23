#pragma once
#include "type.hh"
#include "../project/instance.hh"


/*
				action calling & registering wrapper

description:

	wraps a subclass of nde::action::Type to a functor, so that when
	called, pass its arguments to the constructor of the subclass, and
	then append the new object to nde::project::instance

	in the mean time, the action will be automatically registered
	in nde::action::factory


usage:

	1.	wrap a action. for example, we have nde::action::Undo, then in
		the namespace nde::action, we write:

			Wrapper<Undo> undo{"undo"};

		thus we created the wrapper undo, and registered Undo by string
		name "undo" into nde::action::factory.

	2.	call the wrapper when needed:

			nde::action::undo();

		this action has no parameters, so we pass nothing to the functor.
		if it requires arguments, you can just pass them.


*/

namespace nde
{
	namespace action
	{
		template <class Action>
		struct Wrapper
		{
			template <class ...Ts>
			inline void operator()(Ts... args)
			{
				project::instance.append(new Action{args...});
			}

			Wrapper(const string& name)
			{
				nde::Maker<Action> maker(factory, name);
			}
		};
	};
};

