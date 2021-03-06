import lilliputian as lp

def on_input():
    log_inputs = ["q", "p", "button_a"]
    playerID = 0
    input_api = lp.get_input_api()
    
    if input_api.is_on_release(log_inputs, playerID):
        lp.get_log_api().write("one of " + str(log_inputs) + " was pressed.")
    if input_api.is_on_release("button_b"):
        haptic_playerID = 0
        haptic_strength = 1.0
        haptic_duration_ms = 1000
        
        scene = lp.get_scene_api().get_this_scene()    
        scene.get_haptic_signal_buffer().publish(
            haptic_playerID,
            haptic_strength,
            haptic_duration_ms)
        lp.get_log_api().write("Sent haptic signal; playerID: " +
                               str(haptic_playerID) + ", strength: " +
                               str(haptic_strength) + ", duration: " +
                               str(haptic_duration_ms) + "ms")
