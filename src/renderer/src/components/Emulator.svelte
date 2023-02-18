<script lang="ts">
	import {Route, Router} from "svelte-navigator";
	import Settings from "../routes/Settings.svelte";
	import Home from "../routes/Home.svelte";
</script>

<section class="emulator">
	<img class="hero" src="$assets/hero.png" alt="hero" />

	<div class="content">
		<Router>
			<Route path="/settings">
				<Settings />
			</Route>

			<Route path="/">
				<Home />
			</Route>
		</Router>
	</div>
</section>

<style lang="scss">
@import "../Config.scss";

.hero {
  position: absolute;
  top: 0;
  height: calc(100vh - 50px);
  right: 0;
}

.content {
  position: absolute;
  top: 0;
  left: 0;
  height: calc(100vh - 50px);
  width: calc(100vw - 60px);
  overflow: auto;
}

.emulator {
  width: calc(100vw - 60px);
  height: calc(100vh - 50px);
  background: $l2;
  color: $f1;
  font-family: "Cascadia Mono";
  font-size: 13px;
  padding: 10px;
  user-select: none;
  position: relative;
}
</style>