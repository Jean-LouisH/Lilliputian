import lilliputian as lp


def on_input():
    if lp.get_input_api().is_on_release("escape"):
        lp.get_scene_api().change_to_scene("assets/scenes/splash_screen.yml")

