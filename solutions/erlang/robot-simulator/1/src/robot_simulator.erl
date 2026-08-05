-module(robot_simulator).
-behaviour(gen_server).
-export([advance/1, create/0, direction/1, left/1, place/3, position/1, right/1]).
-export([init/1, handle_cast/2, handle_call/3]).

create() -> 
  {ok, Pid} = gen_server:start(robot_simulator, [], [] ),
  Pid.

direction(Robot) -> gen_server:call(Robot, direction).
position(Robot) -> gen_server:call(Robot, position).

left(Robot) -> gen_server:cast(Robot, left).
right(Robot) -> gen_server:cast(Robot, right).
advance(Robot) -> gen_server:cast(Robot, advance).

place(Robot, Direction, Position) -> gen_server:cast(Robot, {place, Direction, Position}).

%%%

init(_Args) ->
  {ok, {north, {0, 0}}}.

handle_cast({place, Direction, Position},_State) ->
  {noreply, {Direction, Position}};
handle_cast(advance, State) -> {noreply, move_forward(State)};
handle_cast(Twist, State) -> {noreply, turn(Twist, State)}.

handle_call(direction, _From, {Dir, {_X, _Y}} = State) ->
  {reply, Dir, State};
handle_call(position, _From, {_Dir, {X, Y}} = State) ->
  {reply, {X, Y}, State}.

%%%

turn(left, {north, Position}) -> {west, Position};
turn(right,{north, Position}) -> {east, Position};
turn(left, {east, Position}) -> {north, Position};
turn(right,{east, Position}) -> {south, Position};
turn(left, {south, Position}) -> {east, Position};
turn(right,{south, Position}) -> {west, Position};
turn(left, {west, Position}) -> {south, Position};
turn(right,{west, Position}) -> {north, Position}.

move_forward({north, {X, Y}}) -> {north, {X, Y + 1}};
move_forward({south, {X, Y}}) -> {south, {X, Y - 1}};
move_forward({east, {X, Y}}) -> {east, {X + 1, Y}};
move_forward({west, {X, Y}}) -> {west, {X - 1, Y}}.

