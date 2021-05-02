##### Изменения

- game.cpp разнесена на несколько сущностей: `framework/math/vector.hpp` - векторная математика; `game_cpp/object/ship.hpp` - класс корабля; `game_cpp/common.hpp` - конфигурационные параметры
- для класса Vector2D (`framework/math/vector.hpp`) дописаны недостающие векторные операции

##### Нововведения

- новый класс `game_cpp/object/target.hpp` - обертка над целью для самолета

- `framework/entity/entity.hpp` - интерфейсы для игровых объектов (Entity, PhysicalEntity, MoveableEntity, ControlledEntity)
- класс самолета `game_cpp/object/aircraft.hpp` - реализует логику движения к цели
- класс контроллера самолетов `game_cpp/aircraft_controller.hpp` - контейнер самолетов, следит за их состоянием и отдает команды вернуться на корабль

