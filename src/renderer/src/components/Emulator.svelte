<script lang="ts">
	import {Route, Router} from "svelte-navigator";
	import Settings from "../routes/Settings.svelte";
	import Home from "../routes/Home.svelte";
</script>

<section class="emulator">
	<Router>
		<Route path="/settings">
			<Settings />
		</Route>

		<Route path="/">
			<Home />
		</Route>
	</Router>
</section>

<style lang="scss">
@import "../Config.scss";

.emulator {
  width: calc(100vw - 60px);
  height: calc(100vh - 50px);
  color: $f1;
  font-family: "Cascadia Mono";
  font-size: 13px;
  padding: 10px;
  user-select: none;
  background: rgba(0, 0, 0, 90%);
}
</style>