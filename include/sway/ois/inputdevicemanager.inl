#include <sway/ois/inputdevicemanager.h>

template<typename TYPE>
void InputDeviceManager::registerDevice() {
	auto deviceType = core::detail::toUnderlying(TYPE::getDeviceType());
	auto device = boost::bind(boost::factory<std::shared_ptr<TYPE>>(), this);

	_factories.insert(std::make_pair(deviceType, device));
}

template<typename TYPE>
std::shared_ptr<TYPE> InputDeviceManager::getDevice() {
	return std::static_pointer_cast<TYPE>(_factories.at(core::detail::toUnderlying(TYPE::getDeviceType()))());
}