#pragma once

class  Game;

class  Command
{
public:
	 virtual ~Command() {}
	 virtual void execute(Game& game) = 0;
private:
};

 class PausedCommand : public Command
 {
 public:
	 ~PausedCommand();
	 virtual void execute(Game& game) override;

 private:

 };

 class MoveRightCommand : public Command
 {
 public:
	 ~MoveRightCommand();
	 virtual void execute(Game& game) override;
 private:
	 
 };

 class MoveLeftCommand : public Command
 {
 public:
	 ~MoveLeftCommand();
	 virtual void execute(Game& game) override;
 private:

 };

 class MoveUpCommand : public Command
 {
 public:
	 ~MoveUpCommand();
	 virtual void execute(Game& game) override;
 private:

 };

 class MoveDownCommand : public Command
 {
 public:
	 ~MoveDownCommand();
	 virtual void execute(Game& game) override;
 private:

 };

 class AttackCommand : public Command
 {
 public:
	 ~AttackCommand();
	 virtual void execute(Game& game) override;
 private:

 };

 class ShoutCommand : public Command
 {
 public:
	 ~ShoutCommand();
	 virtual void execute(Game& game) override;
 private:

 };



 